import { Component, OnInit } from '@angular/core';
import { ExampleService } from 'src/app/global/services/example/example.service';
import { SocketsService } from 'src/app/global/services';
import { ActivatedRoute, Router} from '@angular/router';
import data from '../json_data/data.json';

@Component({
  selector: 'ami-fullstack-phone',
  templateUrl: './phone.component.html',
  styleUrls: ['./phone.component.scss']
})
export class PhoneComponent implements OnInit {

  public qcounter: number;
  public isCorrect: number;
  ID: string;
  PassFlag: Number;
  SaboFlag: Number;
  socketEvents: {event: string, message: any}[];
  public players: {event: string, message: any}[];
  

  constructor(private route:ActivatedRoute, private exampleService: ExampleService, private socketService: SocketsService) {
    this.PassFlag = 1;
    this.SaboFlag = 1;
    this.socketEvents = [];
    this.players = [];
    this.isCorrect = 0;


  }

  ngOnInit() { 
    //this.qcounter = 0;
    this.ID = this.route.snapshot.paramMap.get("id");
    this.newPlayer();
    this.socketService.syncMessages("timer").subscribe(msg => {if(msg.message==0){
      this.correctAnswer();
    }
    else if(msg.message==1){
      this.qcounter++;
      this.renew();
    }
    else{
      this.qcounter = msg.message%100;
      this.renew();
    }
  })

    this.renew();
  }


  public newPlayer(){
    this.exampleService.newPlayer(this.ID).subscribe();
  }

  drop() {
    document.getElementById("myDropdown").classList.toggle("show");
  }

  getID(){
    return this.ID;
  }

  /*
  // Close the dropdown menu if the user clicks outside of it
  window.onclick = function(event) {
    if (!event.target.matches('.dropbtn')) {
      var dropdowns = document.getElementsByClassName("dropdown-content");
      var i;
      for (i = 0; i < dropdowns.length; i++) {
        var openDropdown = dropdowns[i];
        if (openDropdown.classList.contains('show')) {
          openDropdown.classList.remove('show');
        }
      }
    }
  }
  */

  //sets new question
  public async renew(){
    this.reset();
    var question = document.getElementById('spm_question_sentence');
    question.innerHTML = data.questions[this.qcounter];

    var answers = document.getElementsByClassName('span0');
    answers[1].innerHTML = data.answer1[this.qcounter];
    answers[3].innerHTML = data.answer2[this.qcounter];
    answers[5].innerHTML = data.answer3[this.qcounter];
    answers[7].innerHTML = data.answer4[this.qcounter];
  }
  
  

  public checkAnswer(idi){
    var corr = data.correct[this.qcounter];
    if (++corr == idi[15]){
      this.isCorrect = 1;
    }
    else{
      this.isCorrect = 0;
    }

  }
  

  public async wait(time){
    await this.delay(time);
  }

  delay(ms: number) {
  return new Promise( resolve => setTimeout(resolve, ms) );
  }


    public correctAnswer(){
      var x = data.correct[this.qcounter];
      var answers = document.getElementsByClassName('spm_Answer');
      var spans = document.getElementsByClassName('span0');
      answers[x].id = ("spm_Answer_Corr");
      spans[2*x +1].id = ("span3");
      spans[2*x].id = ("span3");
      this.exampleService.submitAnswer(this.isCorrect +this.getID()).subscribe();
      this.isCorrect = 0;
    }
  
    public reset(){
     var answers = document.getElementsByClassName('spm_Answer');
     var spans = document.getElementsByClassName('span0');
     answers[0].id = ("spm_Answer_idle1");
     answers[1].id = ("spm_Answer_idle2");
     answers[2].id = ("spm_Answer_idle3");
     answers[3].id = ("spm_Answer_idle4");
     spans[0].id = ("span1");
     spans[1].id = ("span2");
     spans[2].id = ("span1");
     spans[3].id = ("span2");
     spans[4].id = ("span1");
     spans[5].id = ("span2");
     spans[6].id = ("span1");
     spans[7].id = ("span2");
    }
  
    public changeState(idi){
      document.getElementById(idi).id="spm_Answer_Pend";
      var els = document.getElementsByClassName('span0');
      if(idi[15] == 1){
        els[0].id = "span3";
        els[1].id = "span3";
      }
      else if(idi[15] == 2){
        els[2].id = "span3";
        els[3].id = "span3";
      }
      else if(idi[15] == 3){
        els[4].id = "span3";
        els[5].id = "span3";
      }
      else if(idi[15] == 4){
        els[6].id = "span3";
        els[7].id = "span3";
      }

      this.checkAnswer(idi);
    }
  
  
  
    Pass(){
      if (this.PassFlag == 1) {
        alert("Pass Used");
        this.PassFlag = 0;
      }
      else{
        alert("Pass Use not allowed");
      }
      
    }
  
    Sabo(){
      if (this.SaboFlag == 1) {
        alert("Sabotage Used");
        this.SaboFlag = 0;
      }
      else{
        alert("Sabotage Use not allowed");
      }
      
    }

}



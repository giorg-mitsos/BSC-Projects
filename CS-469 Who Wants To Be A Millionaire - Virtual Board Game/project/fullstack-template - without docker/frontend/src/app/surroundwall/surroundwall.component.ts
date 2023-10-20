import { Component, OnInit } from '@angular/core';
import { SmartSpeakerService } from '../smart-speaker.service';
import { ExampleService } from 'src/app/global/services/example/example.service';
import { SocketsService } from 'src/app/global/services';
import { ActivatedRoute, Router} from '@angular/router';
import  data from '../json_data/data.json';



@Component({
  selector: 'ami-fullstack-surroundwall',
  templateUrl: './surroundwall.component.html',
  styleUrls: ['./surroundwall.component.scss']
})



export class SurroundwallComponent implements OnInit {

  public hashCo: number;
  public QuestNo: number;
  public players: {event: string, message: any}[];
  public playerCo: number;
  public moneyPointer_pos: number;

  constructor(private route:ActivatedRoute, private exampleService: ExampleService, private socketService: SocketsService) { 
    this.players=[];
  }
  
  ngOnInit() {
    const speaker = new SmartSpeakerService();
    this.hashCo = 0;
    this.QuestNo = 0;
    this.playerCo = 0;
    this.moneyPointer_pos = 0;
    speaker.addCommand('next',() => {this.nexthashtag();this.hashCo++;});

    //when a new player connects renew the name in surroundwall
    this.socketService.syncMessages("newplayer").subscribe(msg => {
      //alert(msg.message);
      if (this.playerCo<=2){
        this.playerCo++;
        this.players.push(msg);
        this.addPlayer(msg.message);
        this.exampleService.timer(100+this.QuestNo).subscribe();
        if(this.playerCo == 1){
          this.start();
        }
      }
    })

    this.socketService.syncMessages("submitAnswer").subscribe(msg =>{
      
      this.updateMoney(msg.message);
    })
    
  }

  delay(ms: number) {
    return new Promise( resolve => setTimeout(resolve, ms) );
    }

  public updateMoney(str){
    let x =Number(str[0]);
    let id: string = str;
    id=id.substring(1);
    let i=0;
    while(id != this.players[i].message){
      i++;
    }
    i++;
    if (x == 1){
      var y = document.getElementById("player"+i+"money");
      console.log("Setting Player: " + id +" money: "+data.money_checkpoints[this.QuestNo]);
      y.innerHTML = data.money_checkpoints[this.QuestNo];
    }
    else{
      var y = document.getElementById("pl"+i);
      y.className = "sw_money_counter_player_red";
    }
  }

  public async start(){
    await this.delay(15000);
    this.exampleService.timer(0).subscribe();
    await this.delay(3000);
    this.exampleService.timer(1).subscribe();
    this.update();
  }

  public moneyPointer_up(){
    var x = document.getElementById("sw_money_pointer");
    this.moneyPointer_pos -= 31.5; 
    x.style.marginTop = this.moneyPointer_pos +"px";
  }
    
  public nextQuestion(){
    var x = document.getElementById("question_des");
    x.innerHTML =data.questions[this.QuestNo];
    x = document.getElementById("a1");
    x.innerHTML ="A: " + data.answer1[this.QuestNo];
    x = document.getElementById("a2");
    x.innerHTML ="B: " + data.answer2[this.QuestNo];
    x = document.getElementById("a3");
    x.innerHTML ="D: " + data.answer4[this.QuestNo];
    x = document.getElementById("a4");
    x.innerHTML ="C: " + data.answer3[this.QuestNo];
    x = document.getElementById("answer_info");
    x.innerHTML =data.answer_info[this.QuestNo];

    x = document.getElementById("bar1");
    x.style.height = data.percpx1[this.QuestNo];
    x = document.getElementById("perc1");
    x.innerHTML = data.perc1[this.QuestNo];

    x = document.getElementById("bar2");
    x.style.height = data.percpx2[this.QuestNo];
    x = document.getElementById("perc2");
    x.innerHTML = data.perc2[this.QuestNo];

    x = document.getElementById("bar3");
    x.style.height = data.percpx3[this.QuestNo];
    x = document.getElementById("perc3");
    x.innerHTML = data.perc3[this.QuestNo];

    x = document.getElementById("bar4");
    x.style.height = data.percpx4[this.QuestNo];
    x = document.getElementById("perc4");
    x.innerHTML = data.perc4[this.QuestNo];
  }
    

  

  public addPlayer(name){
    var x = document.getElementById("player"+this.playerCo);
    x.innerHTML = String(name);
    x = document.getElementById("player"+this.playerCo+"money");
    x.innerHTML = "0€"
  }

  public nexthashtag(){
    var x = document.getElementById("hashtag");
    x.innerHTML = String(data.hashtags[this.hashCo]);
  }

  public update(){
    this.nextQuestion();
    this.moneyPointer_up();
    this.start();
    this.QuestNo++;

  }



}


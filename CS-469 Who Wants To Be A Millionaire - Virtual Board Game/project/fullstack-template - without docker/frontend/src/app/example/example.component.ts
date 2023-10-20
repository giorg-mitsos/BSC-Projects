import { Component, OnInit } from '@angular/core';
import { ExampleService } from 'src/app/global/services/example/example.service';
import { SocketsService } from 'src/app/global/services';
import { ActivatedRoute, Router} from '@angular/router';

@Component({
  selector: 'ami-fullstack-example',
  templateUrl: './example.component.html',
  styleUrls: ['./example.component.scss'],
})


export class ExampleComponent implements OnInit {

  public myUserID;
  public userIDtoTreat;
  public foodToTreat;
  public socketEvents: {event: string, message: any}[];
  public players: {event: string, message: any}[];

  constructor(private route:ActivatedRoute, private exampleService: ExampleService, private socketService: SocketsService) { 

    this.socketEvents=[];
    this.players=[];
  }

  ngOnInit() {
    this.myUserID = this.route.snapshot.paramMap.get("id");
    this.userIDtoTreat = "userToTreat";
    this.foodToTreat = "mousakas";
    this.socketService.syncMessages("treating").subscribe(msg => {
      this.socketEvents.push(msg);
    })

    this.socketService.syncMessages("newplayer").subscribe(msg => {
      alert(msg.message);
      this.players.push(msg);
    })

    this.newPlayer();
    


  }

  public newPlayer(){
    this.exampleService.newPlayer("giwrgos").subscribe();
  }

  public treatSomeone(){
    this.exampleService.treatSomeone(this.foodToTreat,this.userIDtoTreat,"browser"+this.myUserID).subscribe();
  }

  public al(){
    alert(this.players[0].message);
    //alert(this.socketEvents[1].event);
    //alert(this.socketEvents[1].message);
    this.socketEvents.pop();
  }

}

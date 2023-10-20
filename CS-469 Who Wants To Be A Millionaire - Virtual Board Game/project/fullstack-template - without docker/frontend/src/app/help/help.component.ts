import { Component, OnInit } from '@angular/core';
import {SmartSpeakerService} from '../smart-speaker.service';
import { ActivatedRoute, Router} from '@angular/router';

@Component({
  selector: 'ami-fullstack-help',
  templateUrl: './help.component.html',
  styleUrls: ['./help.component.scss']
})
export class HelpComponent implements OnInit {

  constructor(public router: Router) { }

  ngOnInit() {
    const speaker = new SmartSpeakerService();
    speaker.addCommand('life',() =>{this.lifelines();});
    speaker.addCommand('lifelines',() =>{this.lifelines();});
    speaker.addCommand('go to life',() =>{this.lifelines();});
    speaker.addCommand('go to lifelines',() =>{this.lifelines();});
    speaker.addCommand('commands and gestures',() =>{this.commands();});
    speaker.addCommand('commands',() =>{this.commands();});
    speaker.addCommand('gestures',() =>{this.commands();});
    speaker.addCommand('go to commands and gestures',() =>{this.commands();});
    speaker.addCommand('how to play',() =>{this.howtoplay();});
    speaker.addCommand('go to how to play',() =>{this.howtoplay();});
    speaker.addCommand('winning conditions',() =>{this.winningcond();});
    speaker.addCommand('go to winning conditions',() =>{this.winningcond();});
    speaker.addCommand('back',() =>{this.amltv();});
    speaker.addCommand('go back',() =>{this.amltv();});



  }


  public lifelines() {
    this.router.navigate(['/lifelines']);
  }

  public commands() {
    this.router.navigate(['/commands']);
  }

  public howtoplay() {
    this.router.navigate(['/howtoplay']);
  }

  public winningcond() {
    this.router.navigate(['/winningcond']);
  }

  public amltv() {
    this.router.navigate(['/amltv']);

  }

}

import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'ami-fullstack-menuphone',
  templateUrl: './menuphone.component.html',
  styleUrls: ['./menuphone.component.scss']
})
export class MenuphoneComponent implements OnInit {
  name: string;

  constructor(public router: Router) {
    
   }

  ngOnInit() {
  }

  setName(){
    this.name = (<HTMLInputElement>document.getElementById("name")).value;
  }

  getName() {
    return this.name;
  }
 
  navigator(){
    this.router.navigate(['/phone/' + this.getName()]);
  }

}

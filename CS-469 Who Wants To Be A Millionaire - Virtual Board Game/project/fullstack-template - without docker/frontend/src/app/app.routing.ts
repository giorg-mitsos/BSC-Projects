import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { AmltvComponent } from './amltv/amltv.component';
import { CommandsComponent } from './commands/commands.component';
import { ExitComponent } from './exit/exit.component';
import { HelpComponent } from './help/help.component';
import { HighscoresComponent } from './highscores/highscores.component';
import { HowtoplayComponent } from './howtoplay/howtoplay.component';
import { JoinliveComponent } from './joinlive/joinlive.component';
import { LifelinesComponent } from './lifelines/lifelines.component';
import { MenuphoneComponent } from './menuphone/menuphone.component';
import { PhoneComponent } from './phone/phone.component';
import { StartComponent } from './start/start.component';
import { SurroundwallComponent } from './surroundwall/surroundwall.component';
import { WinningcondComponent } from './winningcond/winningcond.component';
import { PhoneHelpComponent } from './phone-help/phone-help.component';
import { CommandsandgesturesPhoneComponent } from './commandsandgestures-phone/commandsandgestures-phone.component';
import { PhoneHowToPlayComponent} from './phone-how-to-play/phone-how-to-play.component';
import { PhoneWinningConditionsComponent} from './phone-winning-conditions/phone-winning-conditions.component';
import { LifelinesPhoneComponent} from './lifelines-phone/lifelines-phone.component';
import { ExampleComponent} from './example/example.component';

const routes: Routes = [
  //{ path: 'home', loadChildren: () => import('./pages/home/home.module').then(m => m.HomeModule) },
  //{ path: 'socket-events', loadChildren: () => import('./pages/socket-events/socket-events.module').then(m => m.SocketEventsModule) },
  //{ path: 'tasks', loadChildren: () => import('./pages/tasks/tasks.module').then(m => m.TasksModule) },
  //{ path: '**', redirectTo: 'home', pathMatch: 'full' },
  { path: 'amltv', component: AmltvComponent},
  { path: 'highscores', component: HighscoresComponent},
  { path: 'help', component: HelpComponent},
  { path: 'start', component: StartComponent},
  { path: 'howtoplay', component: HowtoplayComponent},
  { path: 'commands', component: CommandsComponent},
  { path: 'lifelines', component: LifelinesComponent},
  { path: 'winningcond', component: WinningcondComponent},
  { path: 'menuphone', component: MenuphoneComponent},
  { path: 'joinlive', component: JoinliveComponent},
  { path: 'phone/:id', component: PhoneComponent},
  { path: 'surroundwall', component: SurroundwallComponent},
  { path: 'exit', component: ExitComponent},
  { path: 'phone-help', component: PhoneHelpComponent},
  { path: 'commandsandgesturesPhone', component: CommandsandgesturesPhoneComponent},
  { path: 'PhoneHowToPlay' , component: PhoneHowToPlayComponent},
  { path: 'PhoneWinningConditions' , component: PhoneWinningConditionsComponent},
  { path: 'PhoneLifelines' , component: LifelinesPhoneComponent},
  { path: 'example/:id' , component: ExampleComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }

import { BrowserModule } from '@angular/platform-browser';
import { HttpClientModule } from '@angular/common/http';
import { NgModule } from '@angular/core';
import { AppComponent } from './app.component';
import { AppRoutingModule } from './app.routing';
import { AmltvComponent } from './amltv/amltv.component';
import { PhoneComponent } from './phone/phone.component';
import { SurroundwallComponent } from './surroundwall/surroundwall.component';
import { HelpComponent } from './help/help.component';
import { HighscoresComponent } from './highscores/highscores.component';
import { JoinliveComponent } from './joinlive/joinlive.component';
import { LifelinesComponent } from './lifelines/lifelines.component';
import { CommandsComponent } from './commands/commands.component';
import { ExitComponent } from './exit/exit.component';
import { StartComponent } from './start/start.component';
import { WinningcondComponent } from './winningcond/winningcond.component';
import { HowtoplayComponent } from './howtoplay/howtoplay.component';
import { MenuphoneComponent } from './menuphone/menuphone.component';
import { PhoneHelpComponent } from './phone-help/phone-help.component';
import { CommandsandgesturesPhoneComponent } from './commandsandgestures-phone/commandsandgestures-phone.component';
import { PhoneHowToPlayComponent } from './phone-how-to-play/phone-how-to-play.component';
import { PhoneWinningConditionsComponent } from './phone-winning-conditions/phone-winning-conditions.component';
import { LifelinesPhoneComponent } from './lifelines-phone/lifelines-phone.component';
import { ExampleComponent } from './example/example.component';


@NgModule({
  declarations: [
    AppComponent,
    AmltvComponent,
    PhoneComponent,
    SurroundwallComponent,
    HelpComponent,
    HighscoresComponent,
    JoinliveComponent,
    LifelinesComponent,
    CommandsComponent,
    ExitComponent,
    StartComponent,
    WinningcondComponent,
    HowtoplayComponent,
    MenuphoneComponent,
    PhoneHelpComponent,
    CommandsandgesturesPhoneComponent,
    PhoneHowToPlayComponent,
    PhoneWinningConditionsComponent,
    LifelinesPhoneComponent,
    ExampleComponent,


  ],
  imports: [
    BrowserModule,
    HttpClientModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }

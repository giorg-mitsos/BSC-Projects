import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { CommandsandgesturesPhoneComponent } from './commandsandgestures-phone.component';

describe('CommandsandgesturesPhoneComponent', () => {
  let component: CommandsandgesturesPhoneComponent;
  let fixture: ComponentFixture<CommandsandgesturesPhoneComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ CommandsandgesturesPhoneComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(CommandsandgesturesPhoneComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

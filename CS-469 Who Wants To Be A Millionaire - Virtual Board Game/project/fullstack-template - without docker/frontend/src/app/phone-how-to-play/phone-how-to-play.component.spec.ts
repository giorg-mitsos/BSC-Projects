import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { PhoneHowToPlayComponent } from './phone-how-to-play.component';

describe('PhoneHowToPlayComponent', () => {
  let component: PhoneHowToPlayComponent;
  let fixture: ComponentFixture<PhoneHowToPlayComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ PhoneHowToPlayComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(PhoneHowToPlayComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

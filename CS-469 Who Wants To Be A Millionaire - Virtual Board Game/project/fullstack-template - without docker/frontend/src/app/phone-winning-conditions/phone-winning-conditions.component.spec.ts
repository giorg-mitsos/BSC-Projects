import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { PhoneWinningConditionsComponent } from './phone-winning-conditions.component';

describe('PhoneWinningConditionsComponent', () => {
  let component: PhoneWinningConditionsComponent;
  let fixture: ComponentFixture<PhoneWinningConditionsComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ PhoneWinningConditionsComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(PhoneWinningConditionsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

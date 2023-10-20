import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { PhoneHelpComponent } from './phone-help.component';

describe('PhoneHelpComponent', () => {
  let component: PhoneHelpComponent;
  let fixture: ComponentFixture<PhoneHelpComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ PhoneHelpComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(PhoneHelpComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

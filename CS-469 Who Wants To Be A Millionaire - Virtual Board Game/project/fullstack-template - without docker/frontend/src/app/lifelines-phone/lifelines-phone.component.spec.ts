import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { LifelinesPhoneComponent } from './lifelines-phone.component';

describe('LifelinesPhoneComponent', () => {
  let component: LifelinesPhoneComponent;
  let fixture: ComponentFixture<LifelinesPhoneComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ LifelinesPhoneComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(LifelinesPhoneComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

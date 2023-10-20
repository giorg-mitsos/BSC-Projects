import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AmltvComponent } from './amltv.component';

describe('AmltvComponent', () => {
  let component: AmltvComponent;
  let fixture: ComponentFixture<AmltvComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AmltvComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AmltvComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

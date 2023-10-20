import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { JoinliveComponent } from './joinlive.component';

describe('JoinliveComponent', () => {
  let component: JoinliveComponent;
  let fixture: ComponentFixture<JoinliveComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ JoinliveComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(JoinliveComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

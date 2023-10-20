import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { WinningcondComponent } from './winningcond.component';

describe('WinningcondComponent', () => {
  let component: WinningcondComponent;
  let fixture: ComponentFixture<WinningcondComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ WinningcondComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(WinningcondComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

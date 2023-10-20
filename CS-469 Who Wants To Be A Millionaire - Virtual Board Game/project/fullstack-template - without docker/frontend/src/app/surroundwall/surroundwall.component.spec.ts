import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { SurroundwallComponent } from './surroundwall.component';

describe('SurroundwallComponent', () => {
  let component: SurroundwallComponent;
  let fixture: ComponentFixture<SurroundwallComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ SurroundwallComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(SurroundwallComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

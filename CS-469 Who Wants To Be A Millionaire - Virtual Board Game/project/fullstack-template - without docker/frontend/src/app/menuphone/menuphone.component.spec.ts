import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { MenuphoneComponent } from './menuphone.component';

describe('MenuphoneComponent', () => {
  let component: MenuphoneComponent;
  let fixture: ComponentFixture<MenuphoneComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ MenuphoneComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(MenuphoneComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

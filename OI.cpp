#include "OI.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Elevator/Raise.h"
#include "Commands/Collector/OpenCollector.h"
#include "Commands/Collector/CloseCollector.h"
#include "Commands/Collector/CollectTote.h"
#include "Commands/Collector/ReleaseTote.h"

OI::OI() {
  // Joysticks
  leftStick=new Joystick(0);
  rightStick=new Joystick(1);
  // Collector
  JoystickButton *right1=new JoystickButton(rightStick, 1);
  JoystickButton *right2=new JoystickButton(rightStick, 2);
  JoystickButton *left3=new JoystickButton(leftStick, 3);
  JoystickButton *left4=new JoystickButton(leftStick, 4);
  right1->WhileHeld(new OpenCollector());
  right2->WhileHeld(new CloseCollector());
  left3->WhileHeld(new CollectTote());
  left4->WhileHeld(new ReleaseTote());
  // Elevator
  Raise* raise=new Raise();
  Lower* lower=new Lower();
  JoystickButton *right3=new JoystickButton(rightStick, 3);
  JoystickButton *right4=new JoystickButton(rightStick, 4);
  JoystickButton *right5=new JoystickButton(rightStick, 5);
  JoystickButton *right6=new JoystickButton(rightStick, 6);
  right3->WhenPressed(lower);
  right4->WhenPressed(lower);
  right3->CancelWhenPressed(raise);
  right4->CancelWhenPressed(raise);
  right5->WhenPressed(raise);
  right6->WhenPressed(raise);
  right5->CancelWhenPressed(lower);
  right6->CancelWhenPressed(lower);
  // Cancel
  JoystickButton *right12=new JoystickButton(rightStick, 12);
  right12->CancelWhenPressed(raise);
  right12->CancelWhenPressed(lower);
}
Joystick* OI::GetRightStick(){
  return rightStick;
}
Joystick* OI::GetLeftStick(){
  return leftStick;
}
// vim: ts2:sw=2:et

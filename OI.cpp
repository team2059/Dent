#include "OI.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Elevator/Raise.h"
#include "Commands/Collector/OpenCollector.h"
#include "Commands/Collector/CloseCollector.h"
#include "Commands/Collector/CollectTote.h"
#include "Commands/Collector/ReleaseTote.h"
#include "Commands/Test/CheckRobot.h"

OI::OI() {
  // Joysticks
  leftStick=new Joystick(0);
  rightStick=new Joystick(1);
  // Collector
  JoystickButton *right1=new JoystickButton(rightStick, 1);
  JoystickButton *right2=new JoystickButton(rightStick, 2);
  JoystickButton *left1=new JoystickButton(leftStick, 1);
  JoystickButton *left2=new JoystickButton(leftStick, 2);
  right1->WhileHeld(new CloseCollector());
  right2->WhileHeld(new OpenCollector());
  left1->WhileHeld(new CollectTote());
  left2->WhileHeld(new ReleaseTote());
  // Elevator
  raise=new Raise();
  lower=new Lower();
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
  JoystickButton *right8=new JoystickButton(rightStick, 8);
  right8->CancelWhenPressed(raise);
  right8->CancelWhenPressed(lower);
  // Basic motor test
  CheckRobot* checkRobot=new CheckRobot();
  JoystickButton *left7=new JoystickButton(leftStick, 7);
  left7->WhenPressed(checkRobot);
}
Joystick* OI::GetRightStick(){
  return rightStick;
}
Joystick* OI::GetLeftStick(){
  return leftStick;
}
// vim: ts=2:sw=2:et

#include "OI.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Elevator/Raise.h"
#include "Commands/Collector/OpenCollector.h"
#include "Commands/Collector/CloseCollector.h"
#include "Commands/Collector/RollIn.h"
#include "Commands/Collector/RollOut.h"
#include "Commands/BinElevator/BinLower.h"
#include "Commands/BinElevator/BinRaise.h"

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
  left1->WhileHeld(new RollIn());
  left2->WhileHeld(new RollOut());
  // Elevator
  raise=new Raise();
  lower=new Lower();
  JoystickButton *right4=new JoystickButton(rightStick, 4);
  JoystickButton *right6=new JoystickButton(rightStick, 6);
  right4->WhenPressed(lower);
  right4->CancelWhenPressed(raise);
  right6->WhenPressed(raise);
  right6->CancelWhenPressed(lower);
  // BinElevator
  JoystickButton *right3=new JoystickButton(rightStick, 3);
  JoystickButton *right5=new JoystickButton(rightStick, 5);
  binRaise=new BinRaise();
  binLower=new BinLower();
  right3->WhenPressed(binLower);
  right3->CancelWhenPressed(binRaise);
  right5->WhenPressed(binRaise);
  right5->CancelWhenPressed(binLower);
  // Cancel
  JoystickButton *right12=new JoystickButton(rightStick, 12);
  right12->CancelWhenPressed(raise);
  right12->CancelWhenPressed(lower);
  right12->CancelWhenPressed(binRaise);
  right12->CancelWhenPressed(binLower);
}
Joystick* OI::GetRightStick(){
  return rightStick;
}
Joystick* OI::GetLeftStick(){
  return leftStick;
}
// vim: ts=2:sw=2:et

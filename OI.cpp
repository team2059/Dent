#include "OI.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Elevator/Raise.h"
#include "Commands/Collector/RollIn.h"
#include "Commands/Collector/RollOut.h"
#include "Commands/Collector/RollVar.h"
#include "Commands/BinElevator/BinLower.h"
#include "Commands/BinElevator/BinRaise.h"
#include "Commands/BinElevator/BinCloseArms.h"
#include "Commands/BinElevator/BinOpenArms.h"
#include "Commands/Autonomous/CollectTote.h"
#include "Commands/Autonomous/ReleaseTote.h"
OI::OI(){
  // Joysticks
  leftStick = new Joystick(0);
  rightStick = new Joystick(1);
  // Collector
  JoystickButton *left1 = new JoystickButton(leftStick, 1);
  JoystickButton *left2 = new JoystickButton(leftStick, 2);
  JoystickButton *left7 = new JoystickButton(leftStick, 7);
  left1->WhileHeld(new RollIn(GetLeftThrottle()));
  left2->WhileHeld(new RollOut(2.0));
  // 0.8 is the multiplier, so they roll at 80% power
  left7->WhileHeld(new RollVar(0.8));
  // Elevator
  raise = new Raise(3.5);
  lower = new Lower(3.0);
  JoystickButton *right4 = new JoystickButton(rightStick, 4);
  JoystickButton *right6 = new JoystickButton(rightStick, 6);
  right4->WhenPressed(lower);
  right4->CancelWhenPressed(raise);
  right6->WhenPressed(raise);
  right6->CancelWhenPressed(lower);
  // BinElevator
  JoystickButton *right3 = new JoystickButton(rightStick, 3);
  JoystickButton *right5 = new JoystickButton(rightStick, 5);
  //JoystickButton *right7 = new JoystickButton(rightStick, 7);
  //JoystickButton *right8 = new JoystickButton(rightStick, 8);
  //right7->WhenPressed(new BinOpenArms());
  //right8->WhenPressed(new BinCloseArms());
  binRaise = new BinRaise(3.0);
  binLower = new BinLower(2.0);
  right3->WhileHeld(binLower);
  right3->CancelWhenPressed(binRaise);
  right5->WhileHeld(binRaise);
  right5->CancelWhenPressed(binLower);
  // Cancel
  JoystickButton *right12 = new JoystickButton(rightStick, 12);
  right12->CancelWhenPressed(raise);
  right12->CancelWhenPressed(lower);
}
Joystick* OI::GetRightStick(){
  return rightStick;
}
Joystick* OI::GetLeftStick(){
  return leftStick;
}
double OI::GetRightThrottle(){
  return (-rightStick->GetRawAxis(3)+1.0)/2;
}
double OI::GetLeftThrottle(){
  return (-leftStick->GetRawAxis(3)+1.0)/2;
}
// vim: ts=2:sw=2:et

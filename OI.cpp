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
  leftStick=new Joystick(0);
  rightStick=new Joystick(1);
  // Collector
  JoystickButton *left10=new JoystickButton(leftStick, 10);
  JoystickButton *left12=new JoystickButton(leftStick, 12);
  JoystickButton *left9=new JoystickButton(leftStick, 9);
  left10->WhileHeld(new RollIn(GetLeftThrottle()));
  left12->WhileHeld(new RollOut(2.0));
  // 0.8 is the multiplier, so they roll at 80% power
  left9->WhileHeld(new RollVar(0.8));
  // Elevator
  raise=new Raise(3.5);
  lower=new Lower(3.0);
  JoystickButton *right9=new JoystickButton(rightStick, 9);
  JoystickButton *right11=new JoystickButton(rightStick, 11);
  right9->WhenPressed(lower);
  right9->CancelWhenPressed(raise);
  right11->WhenPressed(raise);
  right11->CancelWhenPressed(lower);
  // BinElevator
  JoystickButton *right10=new JoystickButton(rightStick, 10);
  JoystickButton *right12=new JoystickButton(rightStick, 12);
  //JoystickButton *right7=new JoystickButton(rightStick, 7);
  //JoystickButton *right8=new JoystickButton(rightStick, 8);
  //right7->WhenPressed(new BinOpenArms());
  //right8->WhenPressed(new BinCloseArms());
  binRaise=new BinRaise(3.0);
  binLower=new BinLower(2.0);
  right10->WhileHeld(binLower);
  right10->CancelWhenPressed(binRaise);
  right12->WhileHeld(binRaise);
  right12->CancelWhenPressed(binLower);
  // Cancel
  JoystickButton *right16=new JoystickButton(rightStick, 16);
  right16->CancelWhenPressed(raise);
  right16->CancelWhenPressed(lower);
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

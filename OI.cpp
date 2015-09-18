#include "OI.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Elevator/Raise.h"
#include "Commands/Elevator/ElevatorCycle.h"
#include "Commands/Collector/RollIn.h"
#include "Commands/Collector/RollOut.h"
#include "Commands/Collector/RollVar.h"
#include "Commands/BinElevator/BinLower.h"
#include "Commands/BinElevator/BinRaise.h"
#include "Commands/BinElevator/BinCloseArms.h"
#include "Commands/BinElevator/BinOpenArms.h"
#include "Commands/BinCollector/BinIn.h"
#include "Commands/BinCollector/BinOut.h"
#include "Commands/Autonomous/CollectTote.h"
#include "Commands/Autonomous/ReleaseTote.h"
OI::OI() {
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
  cycle = new ElevatorCycle();
  JoystickButton *right4 = new JoystickButton(rightStick, 4);
  JoystickButton *right6 = new JoystickButton(rightStick, 6);
  JoystickButton *right7 = new JoystickButton(rightStick, 7);
  JoystickButton *right10 = new JoystickButton(rightStick, 10);
  JoystickButton *right11 = new JoystickButton(rightStick, 11);
  JoystickButton *right12 = new JoystickButton(rightStick, 12);
  right4->WhenPressed(lower);
  right6->WhenPressed(raise);
  right7->WhenPressed(cycle);
  right10->WhenPressed(new BinCloseArms(2));
  right11->WhenPressed(new BinOpenArms(2));
  right4->CancelWhenPressed(raise);
  right6->CancelWhenPressed(lower);
  right4->CancelWhenPressed(cycle);
  right6->CancelWhenPressed(cycle);
  right7->CancelWhenPressed(raise);
  right7->CancelWhenPressed(lower);
  // Killall elevator functions
  right12->CancelWhenPressed(raise);
  right12->CancelWhenPressed(lower);
  right12->CancelWhenPressed(cycle);
  // BinElevator
  JoystickButton *right3 = new JoystickButton(rightStick, 3);
  JoystickButton *right5 = new JoystickButton(rightStick, 5);
  binRaise = new BinRaise(3.0);
  binLower = new BinLower(2.0);
  right3->WhileHeld(binLower);
  right3->CancelWhenPressed(binRaise);
  right5->WhileHeld(binRaise);
  right5->CancelWhenPressed(binLower);

  // BinCollector
  JoystickButton *left3 = new JoystickButton(leftStick, 3);
  JoystickButton *left4 = new JoystickButton(leftStick, 4);
  left3->WhileHeld(new BinIn(2.0));
  left4->WhileHeld(new BinOut(2.0));
}
Joystick* OI::GetRightStick() {
  return rightStick;
}
Joystick* OI::GetLeftStick() {
  return leftStick;
}
double OI::GetRightThrottle() {
  return (-rightStick->GetRawAxis(3)+1.0)/2;
}
double OI::GetLeftThrottle() {
  return (-leftStick->GetRawAxis(3)+1.0)/2;
}
// vim: ts=2:sw=2:et

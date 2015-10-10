#include "OI.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Elevator/Raise.h"
#include "Commands/Elevator/OpenArm.h"
#include "Commands/Elevator/CloseArm.h"
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
#include "Commands/Pneumatics/EnableCompressor.h"
#include "Commands/Pneumatics/DisableCompressor.h"
OI::OI() {
  // Joysticks
  leftStick = new Joystick(0);
  rightStick = new Joystick(1);
  // Collector
  JoystickButton *left1 = new JoystickButton(leftStick, 1);
  JoystickButton *left2 = new JoystickButton(leftStick, 2);
  JoystickButton *left7 = new JoystickButton(leftStick, 7);
  JoystickButton *left8 = new JoystickButton(leftStick, 8);
  JoystickButton *left9 = new JoystickButton(rightStick, 9);
  JoystickButton *left10 = new JoystickButton(rightStick, 10);
  left1->WhileHeld(new RollIn(GetLeftThrottle()));
  left2->WhileHeld(new RollOut(2.0));
  //Disable/enable the compressor
  left7->WhenPressed(new DisableCompressor(2));
  left8->WhenPressed(new EnableCompressor(2));
  //Open front collector wheels
  left9->WhenPressed(new BinOpenArms(2));
  left10->WhenPressed(new BinCloseArms(2));

  // Elevator
  JoystickButton *right4 = new JoystickButton(rightStick, 4);
  JoystickButton *right6 = new JoystickButton(rightStick, 6);
  JoystickButton *right11 = new JoystickButton(rightStick, 11);
  JoystickButton *right12 = new JoystickButton(rightStick, 12);
  right11->WhenPressed(new OpenArm(2));
  right12->WhenPressed(new CloseArm(2));
  //Full speed lift
  right4->WhileHeld(new Lower(3.5,false,1));
  right6->WhileHeld(new Raise(3.5,false,-1));
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

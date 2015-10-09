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
  raise = new Raise(3.5,false,1);
  lower = new Lower(3.0);
  cycle = new ElevatorCycle();
  JoystickButton *left11 = new JoystickButton(leftStick, 11);
  JoystickButton *left12 = new JoystickButton(leftStick, 12);
  JoystickButton *right3 = new JoystickButton(rightStick, 3);
  JoystickButton *right4 = new JoystickButton(rightStick, 4);
  JoystickButton *right5 = new JoystickButton(rightStick, 5);
  JoystickButton *right6 = new JoystickButton(rightStick, 6);
  left11->WhenPressed(new OpenArm(2));
  left12->WhenPressed(new CloseArm(2));
  //Full speed lift
  right4->WhileHeld(new Lower(3.5,false,1));
  right6->WhileHeld(new Raise(3.5,false,-1));
  //Half speed lift
  right5->WhileHeld(new Raise(3.5,false,-0.5));
  right5->WhileHeld(new RollIn(0.35));
  right3->WhileHeld(new Lower(3.5,false,0.5));


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

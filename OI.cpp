#include "OI.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Elevator/Raise.h"
#include "Commands/Elevator/ElevatorCycle.h"
#include "Commands/Collector/RollIn.h"
#include "Commands/Collector/RollOut.h"
#include "Commands/Collector/RollVar.h"
#include "Commands/BinElevator/BinLower.h"
#include "Commands/BinElevator/BinRaise.h"
#include "Commands/BinCollector/BinCloseArms.h"
#include "Commands/BinCollector/BinOpenArms.h"
#include "Commands/BinCollector/BinCloseClaw.h"
#include "Commands/BinCollector/BinOpenClaw.h"
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
  JoystickButton *left9 = new JoystickButton(leftStick, 9);
  JoystickButton *left10 = new JoystickButton(leftStick, 10);
  left1->WhileHeld(new RollIn(GetLeftThrottle()));
  left2->WhileHeld(new RollOut(2.0));
  //Disable/enable the compressor
  left7->WhenPressed(new DisableCompressor(2));
  left8->WhenPressed(new EnableCompressor(2));
  //Open front collector wheels
  left9->WhenPressed(new BinOpenArms(2));
  left10->WhenPressed(new BinCloseArms(2));

  // Elevator
  JoystickButton *right1 = new JoystickButton(rightStick, 1);
  JoystickButton *right2 = new JoystickButton(rightStick, 2);
  JoystickButton *right3 = new JoystickButton(rightStick, 3);
  JoystickButton *right4 = new JoystickButton(rightStick, 4);
  JoystickButton *right5 = new JoystickButton(rightStick, 5);
  JoystickButton *right6 = new JoystickButton(rightStick, 6);

  //Full speed lift
  right3->WhileHeld(new Lower(3.5,false,0.5));
  right5->WhileHeld(new Lower(3.5,false,1));
  right4->WhileHeld(new Raise(3.4,false,-0.5));
  right4->WhileHeld(new RollIn(1));
  right6->WhileHeld(new Raise(3.5,false,-1));

  right1->WhenPressed(new BinOpenClaw(2));
  right2->WhenPressed(new BinCloseClaw(2));
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

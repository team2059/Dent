#include "OI.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Elevator/Raise.h"
#include "Commands/Collector/RollIn.h"
#include "Commands/Collector/RollOut.h"
#include "Commands/ContainerElevator/ContainerLower.h"
#include "Commands/ContainerElevator/ContainerRaise.h"
#include "Commands/ContainerElevator/ContainerCloseArms.h"
#include "Commands/ContainerElevator/ContainerOpenArms.h"
#include "Commands/Autonomous/CollectTote.h"
#include "Commands/Autonomous/ReleaseTote.h"
#include "Commands/Test/CheckRobot.h"
OI::OI(){
  // Joysticks
  leftStick=new Joystick(0);
  rightStick=new Joystick(1);
  // Collector
  JoystickButton *left1=new JoystickButton(leftStick, 1);
  JoystickButton *left2=new JoystickButton(leftStick, 2);
  left1->WhileHeld(new RollIn(GetLeftThrottle()));
  left2->WhileHeld(new RollOut(2.0));
  // Elevator
  raise=new Raise(3.5);
  lower=new Lower(3.0);
  JoystickButton *right4=new JoystickButton(rightStick, 4);
  JoystickButton *right6=new JoystickButton(rightStick, 6);
  right4->WhenPressed(lower);
  right4->CancelWhenPressed(raise);
  right6->WhenPressed(raise);
  right6->CancelWhenPressed(lower);
  // ContainerElevator
  JoystickButton *right3=new JoystickButton(rightStick, 3);
  JoystickButton *right5=new JoystickButton(rightStick, 5);
  //JoystickButton *right7=new JoystickButton(rightStick, 7);
  //JoystickButton *right8=new JoystickButton(rightStick, 8);
  //right7->WhenPressed(new ContainerOpenArms());
  //right8->WhenPressed(new ContainerCloseArms());
  containerRaise=new ContainerRaise(3.0);
  containerLower=new ContainerLower(2.0);
  right3->WhileHeld(containerLower);
  right3->CancelWhenPressed(containerRaise);
  right5->WhileHeld(containerRaise);
  right5->CancelWhenPressed(containerLower);
  // Cancel
  JoystickButton *right12=new JoystickButton(rightStick, 12);
  right12->CancelWhenPressed(raise);
  right12->CancelWhenPressed(lower);
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
double OI::GetRightThrottle(){
  return (-rightStick->GetRawAxis(3)+1.0)/2;
}
double OI::GetLeftThrottle(){
  return (-leftStick->GetRawAxis(3)+1.0)/2;
}
// vim: ts=2:sw=2:et

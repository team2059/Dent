#include "HHRobot.h"
#include "HHBase.h"
HHRobot::HHRobot():
  tmpMotor1(new CANTalon(0)),
  joystick1(new Extreme3dPro(0)){
  }
void HHRobot::Init(){
  printf("Initing\n");
  printf("Code Version: %f\n",0000.1);
}
//Main function used to handle periodic tasks on the robot
void HHRobot::Handler(){
  tmpMotor1->Set(joystick1->GetJoystickAxis("y"));
  SmartDashboard::PutNumber("tmp",joystick1->GetJoystickAxis("y"));
}
// vim: ts=2:sw=2:et

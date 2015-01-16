#include "HHRobot.h"
#include "HHBase.h"
HHRobot::HHRobot():
  DriveStick(new Extreme3dPro(0)),
  //FrontRight,FrontLeft,RearRight,RearLeft
  RobotDrive(new MecanumDrive(40,41,42,43)){
  }
void HHRobot::Init(){
  printf("Initing\n");
  printf("Code Version: %f\n",0000.1);
}
//Main function used to handle periodic tasks on the robot
void HHRobot::Handler(){
  RobotDrive->handler(DriveStick->GetJoystickAxis("x"),DriveStick->GetJoystickAxis("y"),DriveStick->GetJoystickAxis("z"),0);
}
// vim: ts=2:sw=2:et

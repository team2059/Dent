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
  double x,y,z;
  if (DriveStick->GetJoystickButton(1)){
    y = 0;
    z = 0;
  }else{
    y = DriveStick->GetJoystickAxis("y");
    z = DriveStick->GetJoystickAxis("z");
  }
  if (DriveStick->GetJoystickButton(2)){
    x = 0;
    z = 0;
  }else{
    x = DriveStick->GetJoystickAxis("x");
    z = DriveStick->GetJoystickAxis("z");
  }
  RobotDrive->handler(x,y,z,0);
}
// vim: ts=2:sw=2:et

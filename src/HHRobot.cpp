#include "HHRobot.h"
#include "HHBase.h"
HHRobot::HHRobot():
  //
  hhdrive(new RobotDrive(2,0,3,1)),
  joystick1(new Extreme3dPro(0)){
    hhdrive->SetExpiration(0.1);
	hhdrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	hhdrive->SetInvertedMotor(RobotDrive::kRearLeftMotor,true);
  }
void HHRobot::Init(){
  printf("Initing\n");
  printf("Code Version: %f\n",0000.1);
  //Put table values initally to avoid annoying refreshing
}
//Main function used to handle periodic tasks on the robot
void HHRobot::Handler(){
	hhdrive->MecanumDrive_Cartesian(joystick1->GetJoystickAxis("z"), joystick1->GetJoystickAxis("y"), joystick1->GetJoystickAxis("x"));
}
// vim: ts=2:sw=2:et

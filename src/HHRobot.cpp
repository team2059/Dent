#include "HHRobot.h"
#include "HHBase.h"
HHRobot::HHRobot():
  hhdrive(new RobotDrive(2,0,3,1)),
  gyro(new Gyro(1)),
  collector(new DentCollector(4, 5, 6, 7)),
  joystick1(new Extreme3dPro(0)){
    hhdrive->SetExpiration(0.1);
    hhdrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
    hhdrive->SetInvertedMotor(RobotDrive::kRearLeftMotor,true);
  }
void HHRobot::Init(){
  printf("Initing\n");
  printf("Code Version: %f\n",0000.1);
  gyro->Reset();
  //Put table values initally to avoid annoying refreshing
}
//Main function used to handle periodic tasks on the robot
void HHRobot::Handler(){
  const float Kp = 0.3;
  if(joystick1->GetJoystickButton(1)==1){
    hhdrive->MecanumDrive_Cartesian(joystick1->GetJoystickAxis("z"), 0, joystick1->GetJoystickAxis("x"));
  }else if(joystick1->GetJoystickButton(2)==1){
    hhdrive->MecanumDrive_Cartesian(joystick1->GetJoystickAxis("z"), joystick1->GetJoystickAxis("y"), 0);
  }else if(joystick1->GetJoystickButton(3)==1){
    hhdrive->Drive(joystick1->GetJoystickAxis("y"), joystick1->GetJoystickAxis("y")*Kp*-gyro->GetAngle());
  }else{
    hhdrive->MecanumDrive_Cartesian(joystick1->GetJoystickAxis("z"), joystick1->GetJoystickAxis("y"), joystick1->GetJoystickAxis("x"));
  }
  if(joystick1->GetJoystickButton(11)){
    collector->Collect(255);
  }else if(joystick1->GetJoystickButton(12)){
    collector->Collect(1);
  }else if(joystick1->GetJoystickButton(9)){
    collector->Raise(255);
  }else if(joystick1->GetJoystickButton(10)){
    collector->Raise(1);
  }else{
    collector->Rest();
  }
  Wait(0.005);
  // hhdrive->MecanumDrive_Cartesian(joystick1->GetJoystickAxis("z"), joystick1->GetJoystickAxis("y"), joystick1->GetJoystickAxis("x"));
}
// vim: ts=2:sw=2:et

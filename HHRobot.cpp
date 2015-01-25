#include "HHRobot.h"
#include "HHBase.h"
HHRobot::HHRobot():
  hhdrive(new RobotDrive(2,0,3,1)),
  gyro(new Gyro(1)),
  collector(new DentCollector(4, 5, 6, 7)),
  driveStick(new Extreme3dPro(0)){
    hhdrive->SetExpiration(0.1);
    hhdrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
    hhdrive->SetInvertedMotor(RobotDrive::kRearLeftMotor,true);
  }
void HHRobot::Init(){
  printf("Initing\n");
  printf("Code Version: %f\n",0000.1);
  gyro->Reset();
}
//Main function used to handle periodic tasks on the robot
void HHRobot::Handler(){
  const float Kp = 0.3;
  if(driveStick->GetJoystickButton(1)==1){
    hhdrive->MecanumDrive_Cartesian(driveStick->GetJoystickAxis("z"), 0, driveStick->GetJoystickAxis("x"));
  }else if(driveStick->GetJoystickButton(2)==1){
    hhdrive->MecanumDrive_Cartesian(driveStick->GetJoystickAxis("z"), driveStick->GetJoystickAxis("y"), 0);
  }else if(driveStick->GetJoystickButton(3)==1){
    hhdrive->Drive(driveStick->GetJoystickAxis("y"), driveStick->GetJoystickAxis("y")*Kp*-gyro->GetAngle());
  }else{
    hhdrive->MecanumDrive_Cartesian(driveStick->GetJoystickAxis("z"), driveStick->GetJoystickAxis("y"), driveStick->GetJoystickAxis("x"));
  }
  if(driveStick->GetJoystickButton(11)==1){
    collector->Collect(driveStick->GetThrottle());
  }else if(driveStick->GetJoystickButton(12)==1){
    collector->Collect(-driveStick->GetThrottle());
  }else if(driveStick->GetJoystickButton(9)==1){
    collector->Raise(driveStick->GetThrottle());
  }else if(driveStick->GetJoystickButton(10)==1){
    collector->Raise(-driveStick->GetThrottle());
  }else{
    collector->Rest();
  }
  SmartDashboard::PutNumber("hambone1", driveStick->GetThrottle());
  SmartDashboard::PutNumber("hambone2", driveStick->GetJoystickAxis("joystick"));
  SmartDashboard::PutNumber("hambone3", driveStick->GetRawJoystickAxis(3));
  printf("hambone2: %f", driveStick->GetThrottle());
  Wait(0.005);
}
// vim: ts=2:sw=2:et

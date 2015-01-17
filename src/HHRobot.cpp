#include "HHRobot.h"
#include "HHBase.h"
HHRobot::HHRobot():
  DriveStick(new Extreme3dPro(0)),
  AirCompressor(new Compressor(30)),
  PowerDistPanel(new PowerDistributionPanel()),
  //FrontRight,FrontLeft,RearRight,RearLeft
  RobotDrive(new MecanumDrive(40,41,42,43)){
  }
void HHRobot::Init(){
  printf("Initing\n");
}
//Main function used to handle periodic tasks on the robot
void HHRobot::Handler(){
  //Code to lock the axis when driving
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
  //X axis, Y axis, Z axis, acceleration, threshold, gyro
  RobotDrive->handler(x,y,z,0.5,1,0);

  //Disables the compressor if the battery voltage is detected to be less than 10 volts
  if (PowerDistPanel->GetVoltage()<=10){
    AirCompressor->Stop();
  }
}
// vim: ts=2:sw=2:et

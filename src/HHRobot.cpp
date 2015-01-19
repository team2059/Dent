#include "HHRobot.h"
#include "HHBase.h"
HHRobot::HHRobot():
  DriveStick(new Extreme3dPro(0)),
  AirCompressor(new Compressor(31)),
  PowerDistPanel(new PowerDistributionPanel()),
  //FrontRight,FrontLeft,RearRight,RearLeft
  RobotDrive(new MecanumDrive(40,41,42,43)){
  }
void HHRobot::Init(){
  printf("Initing\n");
  AirCompressor->Start();
}
//Main function used to handle periodic tasks on the robot
void HHRobot::Handler(){
  //Code to lock the axis when driving
  double x,y,z;
  if (DriveStick->GetJoystickButton(1)){
    x = DriveStick->GetJoystickAxis("x");
  }else{
    x = 0;
  }
  y = DriveStick->GetJoystickAxis("y");
  z = DriveStick->GetJoystickAxis("z");
  //X axis, Y axis, Z axis, sensitivity, mode threshold, gyro
  RobotDrive->handler(x,y,z,0.95,DriveStick->GetThrottle(),0);
  //Compressor Button assignment
  if (DriveStick->GetJoystickButton(4)){
    AirCompressor->Stop();
  }
}
// vim: ts=2:sw=2:et

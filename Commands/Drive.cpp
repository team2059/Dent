#include "Drive.h"
#include <cmath>
#include "../DentRobot.h"
Drive::Drive() : Command("Drive"){
  Requires(DentRobot::drivetrain);
}
void Drive::Initialize(){
}
void Drive::Execute(){
  double x,y,z;
  //Code to lock the x axis when not holding button 1
  if (DentRobot::oi->GetLeftStick()->GetRawButton(1)){
    x = DentRobot::oi->GetLeftStick()->GetRawAxis(0);
    x /= 1.3;
  }else{
    x = 0;
  }
  z = DentRobot::oi->GetLeftStick()->GetRawAxis(2);
  y = DentRobot::oi->GetLeftStick()->GetRawAxis(1);
  if (DentRobot::oi->GetLeftStick()->GetRawAxis(3)<=0.5){
    y /= 2;
    z /= 2;
  }
  //X axis, Y axis, Z axis, sensitivity, speed threshold (usually throttle), gyro
  DentRobot::drivetrain->DriveMecanum(x,y,z,0.9,0);
}
bool Drive::IsFinished(){
  return false;
}
void Drive::End(){
}
void Drive::Interrupted(){
  End();
}

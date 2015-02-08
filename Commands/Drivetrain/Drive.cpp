#include "Drive.h"
#include <cmath>
#include "../../DentRobot.h"
Drive::Drive() : Command("Drive"){
  Requires(DentRobot::drivetrain);
}
void Drive::Initialize(){
}
void Drive::Execute(){
  double x,y,z;
  //Code to lock the x axis when not holding button 1
  x = DentRobot::oi->GetLeftStick()->GetRawAxis(0);
  z = DentRobot::oi->GetLeftStick()->GetRawAxis(2);
  y = DentRobot::oi->GetLeftStick()->GetRawAxis(1);
  if (DentRobot::oi->GetLeftStick()->GetRawButton(1)){
    x=0;
  }
  if (DentRobot::oi->GetLeftStick()->GetRawButton(2)){
    y=0;
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
// vim: ts=2:sw=2:et

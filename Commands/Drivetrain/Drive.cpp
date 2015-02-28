#include "Drive.h"
#include "../../DentRobot.h"
Drive::Drive() : Command("Drive"){
  Requires(DentRobot::drivetrain);
}
void Drive::Initialize(){
}
void Drive::Execute(){
  double x, y, z;
  x = DentRobot::oi->GetLeftAxis("left", "x");
  y = DentRobot::oi->GetLeftAxis("left", "y");
  z = DentRobot::oi->GetLeftAxis("right", "x");
  //Code to lock the x axis when not holding button 1
  //if (DentRobot::oi->GetLeftStick()->GetRawButton(1)){
  //  x=0;
  //}
  //if (DentRobot::oi->GetLeftStick()->GetRawButton(2)){
  //  y=0;
  //}
  //X axis, Y axis, Z axis, sensitivity, speed threshold (usually throttle), gyro
  DentRobot::drivetrain->DriveMecanum(x, y, z, 0.9, 0.0);
}
bool Drive::IsFinished(){
  return IsTimedOut();
}
void Drive::End(){
}
void Drive::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

#include "Drive.h"
#include "../../DentRobot.h"
Drive::Drive(): Command("Drive"){
  Requires(DentRobot::drivetrain);
}
void Drive::Initialize(){
}
void Drive::Execute(){
  double x, y, z;
  x = DentRobot::oi->GetLeftStick()->GetRawAxis(0);
  y = -DentRobot::oi->GetLeftStick()->GetRawAxis(1);
  z = DentRobot::oi->GetLeftStick()->GetRawAxis(2);
  // Lock the x axis when not holding button 1
  //if(DentRobot::oi->GetLeftStick()->GetRawButton(1)){
  //  x=0;
  //}
  //if(DentRobot::oi->GetLeftStick()->GetRawButton(2)){
  //  y=0;
  //}
  //X axis, Y axis, Z axis, sensitivity, speed threshold (usually throttle)
  DentRobot::drivetrain->DriveMecanum(x, y, z, 0.9);
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

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
  printf("Driving: %f,%f,%f",x,y,z);
  DentRobot::drivetrain->DriveMecanum(x, y, z);
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

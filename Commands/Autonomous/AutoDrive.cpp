#include "AutoDrive.h"
#include "../../DentRobot.h"
// Drive for a short while then stop. Just for testing
AutoDrive::AutoDrive(double duration, double xtmp, double ytmp): Command("AutoDrive"){
  Requires(DentRobot::drivetrain);
  SetTimeout(duration);
  x=xtmp;
  y=ytmp;
}
void AutoDrive::Initialize(){
}
void AutoDrive::Execute(){
  //X axis, Y axis, Z axis, sensitivity, speed threshold (usually throttle)
  DentRobot::drivetrain->DriveMecanum(x, y, 0.0, 0.9);
}
bool AutoDrive::IsFinished(){
  return IsTimedOut();
}
void AutoDrive::End(){
  DentRobot::drivetrain->DriveMecanum(0.0, 0.0, 0.0, 0.9);
}
void AutoDrive::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

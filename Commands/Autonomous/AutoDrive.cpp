#include "AutoDrive.h"
#include <cmath>
#include "../../DentRobot.h"
// Drive for a short while then stop. Just for testing
AutoDrive::AutoDrive() : Command("AutoDrive"){
  Requires(DentRobot::drivetrain);
  SetTimeout(1.0);
}
void AutoDrive::Initialize(){
}
void AutoDrive::Execute(){
  //X axis, Y axis, Z axis, sensitivity, speed threshold (usually throttle), gyro
  DentRobot::drivetrain->DriveMecanum(0.5,0,0,0.9,0);
}
bool AutoDrive::IsFinished(){
  return false;
}
void AutoDrive::End(){
}
void AutoDrive::Interrupted(){
  End();
}
// vim: ts2:sw=2:et

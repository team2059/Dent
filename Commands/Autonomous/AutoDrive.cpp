#include "AutoDrive.h"
#include "../../DentRobot.h"
// Drive for a short while then stop. Just for testing
AutoDrive::AutoDrive(double wait) : Command("AutoDrive"){
  Requires(DentRobot::drivetrain);
  SetTimeout(wait);
  power=5;
}
AutoDrive::AutoDrive(double wait, double p) : Command("AutoDrive"){
  Requires(DentRobot::drivetrain);
  SetTimeout(wait);
  power=p;
}
void AutoDrive::Initialize(){
}
void AutoDrive::Execute(){
  //X axis, Y axis, Z axis, sensitivity, speed threshold (usually throttle), gyro
  //if(power==NULL){
  if(power==5){
    DentRobot::drivetrain->DriveMecanum(0.0,-.75,0.0,0.9,0.0);
  }else{
    DentRobot::drivetrain->DriveMecanum(0.0,power,0.0,0.9,0.0);
  }
}
bool AutoDrive::IsFinished(){
  return IsTimedOut();
}
void AutoDrive::End(){
  DentRobot::drivetrain->DriveMecanum(0.0,0.0,0.0,0.9,0.0);
}
void AutoDrive::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

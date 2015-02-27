#include "Turn.h"
#include "../../DentRobot.h"
// Drive for a short while then stop. Just for testing
Turn::Turn(int k) : Command("Turn"){
  Requires(DentRobot::drivetrain);
  SetTimeout(k);
}
void Turn::Initialize(){
}
void Turn::Execute(){
  //X axis, Y axis, Z axis, sensitivity, speed threshold (usually throttle), gyro
  DentRobot::drivetrain->DriveMecanum(0.0,0.0,0.6,0.9,0.0);
}
bool Turn::IsFinished(){
  return IsTimedOut();
}
void Turn::End(){
  // Stop driving
  DentRobot::drivetrain->DriveMecanum(0.0,0.0,0.0,0.9,0.0);
}
void Turn::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

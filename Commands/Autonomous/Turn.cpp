#include "Turn.h"
#include "../../DentRobot.h"
// Drive for a short while then stop. Just for testing
Turn::Turn() : Command("Turn"){
  Requires(DentRobot::drivetrain);
  SetTimeout(0.25);
}
void Turn::Initialize(){
}
void Turn::Execute(){
  //X axis, Y axis, Z axis, sensitivity, speed threshold (usually throttle), gyro
  DentRobot::drivetrain->DriveMecanum(0.0,0.0,0.5,0.9,0.0);
}
bool Turn::IsFinished(){
  return IsTimedOut();
}
void Turn::End(){
}
void Turn::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

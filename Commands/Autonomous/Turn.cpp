#include "Turn.h"
#include "../../DentRobot.h"
Turn::Turn(double timeout, double pwr): Command("Turn"){
  Requires(DentRobot::drivetrain);
  SetTimeout(timeout);
  power=pwr;
}
void Turn::Initialize(){
}
void Turn::Execute(){
  //X axis, Y axis, Z axis, sensitivity, speed threshold (usually throttle)
  DentRobot::drivetrain->DriveMecanum(0.0, 0.0, power, 0.9);
}
bool Turn::IsFinished(){
  return IsTimedOut();
}
void Turn::End(){
  // Stop driving
  DentRobot::drivetrain->DriveMecanum(0.0, 0.0, 0.0, 0.9);
}
void Turn::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

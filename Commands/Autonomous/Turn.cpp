#include "Turn.h"
#include "../../DentRobot.h"
Turn::Turn(double timeout): Command("Turn"){
  Requires(DentRobot::drivetrain);
  SetTimeout(timeout);
}
void Turn::Initialize(){
}
void Turn::Execute(){
  //X axis, Y axis, Z axis, sensitivity, speed threshold (usually throttle)
}
bool Turn::IsFinished(){
  return IsTimedOut();
}
void Turn::End(){
  // Stop driving
}
void Turn::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

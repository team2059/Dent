#include "RollOut.h"
RollOut::RollOut(double timeout): Command("RollOut"){
  Requires(DentRobot::collector);
  SetTimeout(timeout);
}
void RollOut::Initialize(){
}
void RollOut::Execute(){
  // Divide by 2 twice because this speed should be half the collector speed
  DentRobot::collector->MoveRollers(-DentRobot::oi->GetLeftThrottle() * 0.8);
  SmartDashboard::PutNumber("DriveThrottle", -DentRobot::oi->GetLeftThrottle());
}
bool RollOut::IsFinished(){
  return IsTimedOut();
}
void RollOut::End(){
  DentRobot::collector->MoveRollers(0.0f);
}
void RollOut::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

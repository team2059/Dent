#include "RollOut.h"
RollOut::RollOut() : Command("RollOut"){
  Requires(DentRobot::collector);
}
void RollOut::Initialize(){
  SetTimeout(2.0);
}
void RollOut::Execute(){
  //TODO check this value to move the motors in the right direction
  // Devide by 2 twice because this speed should be half the collector speed
  DentRobot::collector->MoveRollers(-DentRobot::oi->GetLeftThrottle() * 0.8);
  SmartDashboard::PutNumber("DriveThrottle",-DentRobot::oi->GetLeftThrottle());
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

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
  DentRobot::collector->MoveRollers(-(-DentRobot::oi->GetLeftStick()->GetRawAxis(3)+1.0)/2);
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

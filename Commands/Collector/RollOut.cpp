#include "RollOut.h"
RollOut::RollOut() : Command("RollOut"){
  Requires(DentRobot::collector);
}
void RollOut::Initialize(){
  SetTimeout(2.0);
}
void RollOut::Execute(){
  //TODO: figure out how to implement this with an Xbox controller
  //DentRobot::collector->MoveRollers(-DentRobot::oi->GetLeftThrottle() * 0.8);
  //Will just move at .8 power for now
  DentRobot::collector->MoveRollers(-0.8);
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

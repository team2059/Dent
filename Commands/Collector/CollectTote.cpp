#include "CollectTote.h"
CollectTote::CollectTote() : Command("CollectTote"){
  Requires(DentRobot::collector);
}
void CollectTote::Initialize(){
  SetTimeout(2.0);
}
void CollectTote::Execute(){
  //TODO check this value to move the motors in the right direction
  DentRobot::collector->MoveRollers(-(-DentRobot::oi->GetLeftStick()->GetRawAxis(3)+1.0)/2);
}
bool CollectTote::IsFinished(){
  return DentRobot::collector->BoxCollected();
}
void CollectTote::End(){
  DentRobot::collector->MoveRollers(0.0);
}
void CollectTote::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

#include "CollectTote.h"
CollectTote::CollectTote() : Command("CollectTote"){
  Requires(DentRobot::collector);
}
void CollectTote::Initialize(){
}
void CollectTote::Execute(){
  //TODO check this value to move the motors in the right direction
  printf("collecting tote\n");
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

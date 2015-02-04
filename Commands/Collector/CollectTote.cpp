#include "CollectTote.h"
CollectTote::CollectTote() : Command("CollectTote"){
  Requires(DentRobot::collector);
}
void CollectTote::Initialize(){
}
void CollectTote::Execute(){
  //TODO check this value to move the motors in the right direction
  DentRobot::collector->MoveRollers(-1.0);
}
bool CollectTote::IsFinished(){
  return DentRobot::collector->BoxCollected();
}
void CollectTote::End(){
  DentRobot::collector->MoveRollers(0.0f);
}
void CollectTote::Interrupted(){
  End();
}

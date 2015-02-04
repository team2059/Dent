#include "ReleaseTote.h"
ReleaseTote::ReleaseTote() : Command("ReleaseTote"){
  Requires(DentRobot::collector);
}
void ReleaseTote::Initialize(){
}
void ReleaseTote::Execute(){
  //TODO check this value to move the motors in the right direction
  DentRobot::collector->MoveRollers(1.0f);
}
bool ReleaseTote::IsFinished(){
  return DentRobot::collector->BoxCollected();
}
void ReleaseTote::End(){
  DentRobot::collector->MoveRollers(0.0f);
}
void ReleaseTote::Interrupted(){
  End();
}

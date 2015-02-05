#include "ReleaseTote.h"
ReleaseTote::ReleaseTote() : Command("ReleaseTote"){
  Requires(DentRobot::collector);
}
void ReleaseTote::Initialize(){
}
void ReleaseTote::Execute(){
  //TODO check this value to move the motors in the right direction
  printf("releasing tote\n");
  DentRobot::collector->MoveRollers((-DentRobot::oi->GetLeftStick()->GetRawAxis(3)+1.0)/2);
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

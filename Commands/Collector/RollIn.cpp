#include "RollIn.h"
RollIn::RollIn() : Command("RollIn"){
}
void RollIn::Initialize(){
  printf("Initialized RollIn\n");
  SetTimeout(2.0);
}
void RollIn::Execute(){
  //TODO check this value to move the motors in the right direction
  DentRobot::collector->MoveRollers(-(-DentRobot::oi->GetLeftStick()->GetRawAxis(3)+1.0)/2);
}
bool RollIn::IsFinished(){
  return IsTimedOut();
}
void RollIn::End(){
  DentRobot::collector->MoveRollers(0.0);
}
void RollIn::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

#include "RollIn.h"
RollIn::RollIn(double k) : Command("RollIn"){
  rawSpeed=k;
}
void RollIn::Initialize(){
  printf("Initialized RollIn\n");
  SetTimeout(2.0);
}
void RollIn::Execute(){
  double cvt=(rawSpeed)*DentRobot::collector->GetSonarDistance()/0.4;
  if(cvt>=1.0){
    DentRobot::collector->MoveRollers(1.0);
  }else{
    DentRobot::collector->MoveRollers(cvt);
  }
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

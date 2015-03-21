#include "RollIn.h"
RollIn::RollIn(double speed): Command("RollIn"){
  rawSpeed=speed;
}
void RollIn::Initialize(){
  printf("Initialized RollIn\n");
  SetTimeout(2.0);
}
void RollIn::Execute(){
  //double cvt=(rawSpeed)*DentRobot::collector->GetSonarDistance()/0.4;
  //if(cvt<=1.0){
  //  DentRobot::collector->MoveRollers(1.0);
  //}else{
  //  DentRobot::collector->MoveRollers(cvt*1.5);
  //}
  DentRobot::collector->MoveRollers(DentRobot::oi->GetLeftAxis("left", "throttle") * 1.0);
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

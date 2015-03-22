#include "RollVar.h"
RollVar::RollVar(double speedVal): Command("RollVar"){
  speed=speedVal;
}
void RollVar::Initialize(){
  printf("Initialized RollVar\n");
  SetTimeout(2.0);
  Requires(DentRobot::drivetrain);
}
void RollVar::Execute(){
  DentRobot::collector->MoveLeftRoller(1-(speed*(DentRobot::oi->GetLeftStick()->GetRawAxis(2)+1)/2));
  DentRobot::collector->MoveRightRoller(-(speed*(DentRobot::oi->GetLeftStick()->GetRawAxis(2)+1)/2));
  DentRobot::collector->MoveBottomRollers(speed*1.0);
}
bool RollVar::IsFinished(){
  return IsTimedOut();
}
void RollVar::End(){
  DentRobot::collector->MoveRollers(0.0);
}
void RollVar::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

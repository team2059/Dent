#include "OpenCollector.h"
OpenCollector::OpenCollector() : Command("OpenCollector"){
  Requires(DentRobot::collector);
}
void OpenCollector::Initialize(){
  SetTimeout(0.5);
}
void OpenCollector::Execute(){
  DentRobot::collector->MoveArms(0.35);
  //DentRobot::collector->MoveArms((-DentRobot::oi->GetRightStick()->GetRawAxis(3)+1)/2*.3/.5);
}
bool OpenCollector::IsFinished(){
  //return DentRobot::collector->ArmSensor();
  return IsTimedOut();
}
void OpenCollector::End(){
  DentRobot::collector->MoveArms(0.0f);
}
void OpenCollector::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

#include "CloseCollector.h"
CloseCollector::CloseCollector() : Command("CloseCollector"){
  Requires(DentRobot::collector);
}
void CloseCollector::Initialize(){
  SetTimeout(0.5);
}
void CloseCollector::Execute(){
  DentRobot::collector->MoveArms(0.2f);
}
bool CloseCollector::IsFinished(){
  return DentRobot::collector->ArmSensor();
}
void CloseCollector::End(){
  DentRobot::collector->MoveArms(0.0f);
}
void CloseCollector::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

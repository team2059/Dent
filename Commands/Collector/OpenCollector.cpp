#include "OpenCollector.h"
OpenCollector::OpenCollector() : Command("OpenCollector"){
  Requires(DentRobot::collector);
}
void OpenCollector::Initialize(){
  SetTimeout(0.5);
}
void OpenCollector::Execute(){
  //TODO check this value to move the motors in the right direction
  DentRobot::collector->MoveArms(-0.2f);
}
bool OpenCollector::IsFinished(){
  return DentRobot::collector->ArmSensor();
}
void OpenCollector::End(){
  DentRobot::collector->MoveArms(0.0f);
}
void OpenCollector::Interrupted(){
  End();
}
// vim: ts2:sw=2:et

#include "OpenCollector.h"
OpenCollector::OpenCollector() : Command("OpenCollector"){
  Requires(DentRobot::collector);
}
void OpenCollector::Initialize(){
}
void OpenCollector::Execute(){
  //TODO check this value to move the motors in the right direction
  DentRobot::collector->MoveArms(-.1);
}
bool OpenCollector::IsFinished(){
  return DentRobot::collector->ArmSensor();
}
void OpenCollector::End(){
}
void OpenCollector::Interrupted(){
  End();
}

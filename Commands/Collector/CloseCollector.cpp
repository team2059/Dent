#include "CloseCollector.h"
CloseCollector::CloseCollector() : Command("CloseCollector"){
}
void CloseCollector::Initialize(){
  printf("Initialized collector: 0.5\n");
  SetTimeout(1);
}
void CloseCollector::Execute(){
  //printf("Closing collector: -0.5f\n");
  DentRobot::collector->MoveArms(-0.5);
  //DentRobot::collector->MoveArms(-(-DentRobot::oi->GetRightStick()->GetRawAxis(3)+1)/2*.3/.5);
}
bool CloseCollector::IsFinished(){
  if(DentRobot::collector->ArmSensor()||IsTimedOut()){
    printf("Stopped Closing: %d, %d\n",DentRobot::collector->ArmSensor(), IsTimedOut());
    return true;
  }else{
    return false;
  }
}
void CloseCollector::End(){
  DentRobot::collector->MoveArms(0.0f);
}
void CloseCollector::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

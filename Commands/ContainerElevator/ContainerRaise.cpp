#include "CONTAINER_Raise.h"
#include "../../DentRobot.h"
#include "../../OI.h"
CONTAINER_Raise::CONTAINER_Raise(double timeout): Command("CONTAINER_Raise"){
  SetTimeout(timeout);
}
void CONTAINER_Raise::Initialize(){
}
void CONTAINER_Raise::Execute(){
  DentRobot::CONTAINER_Elevator->Run(1.0);
}
bool CONTAINER_Raise::IsFinished(){
  if(/*!DentRobot::CONTAINER_Elevator->GetElevatorTop()||*/IsTimedOut()){
    printf("Robot stoped raising. Sensor based? %d\n", !DentRobot::CONTAINER_Elevator->GetElevatorTop());
    return true;
  }else{
    return false;
  }
}
void CONTAINER_Raise::End(){
  DentRobot::CONTAINER_Elevator->Run(0.0f);
}
void CONTAINER_Raise::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

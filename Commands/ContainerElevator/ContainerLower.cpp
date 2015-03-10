#include "CONTAINER_Lower.h"
#include "../../DentRobot.h"
#include "../../OI.h"
CONTAINER_Lower::CONTAINER_Lower(float timeout): Command("CONTAINER_Lower"){
  SetTimeout(timeout);
}
void CONTAINER_Lower::Initialize(){
}
void CONTAINER_Lower::Execute(){
  DentRobot::CONTAINER_Elevator->Run(-1.0);
}
bool CONTAINER_Lower::IsFinished(){
  if(/*!DentRobot::CONTAINER_Elevator->GetElevatorBottom()||*/IsTimedOut()){
    printf("Robot stoped CONTAINER_Lowering. Sensor based? %d\n", !DentRobot::CONTAINER_Elevator->GetElevatorBottom());
    return true;
  }else{
    return false;
  }
}
void CONTAINER_Lower::End(){
  DentRobot::CONTAINER_Elevator->Run(0.0f);
}
void CONTAINER_Lower::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

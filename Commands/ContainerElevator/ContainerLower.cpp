#include "ContainerLower.h"
#include "../../DentRobot.h"
#include "../../OI.h"
ContainerLower::ContainerLower(float timeout): Command("ContainerLower"){
  SetTimeout(timeout);
}
void ContainerLower::Initialize(){
}
void ContainerLower::Execute(){
  DentRobot::containerElevator->Run(-1.0);
}
bool ContainerLower::IsFinished(){
  if(/*!DentRobot::containerElevator->GetElevatorBottom()||*/IsTimedOut()){
    printf("Robot stoped ContainerLowering. Sensor based? %d\n", !DentRobot::containerElevator->GetElevatorBottom());
    return true;
  }else{
    return false;
  }
}
void ContainerLower::End(){
  DentRobot::containerElevator->Run(0.0f);
}
void ContainerLower::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

#include "ContainerRaise.h"
#include "../../DentRobot.h"
#include "../../OI.h"
ContainerRaise::ContainerRaise(double timeout): Command("ContainerRaise"){
  SetTimeout(timeout);
}
void ContainerRaise::Initialize(){
}
void ContainerRaise::Execute(){
  DentRobot::containerElevator->Run(1.0);
}
bool ContainerRaise::IsFinished(){
  if(/*!DentRobot::containerElevator->GetElevatorTop()||*/IsTimedOut()){
    printf("Robot stoped raising. Sensor based? %d\n", !DentRobot::containerElevator->GetElevatorTop());
    return true;
  }else{
    return false;
  }
}
void ContainerRaise::End(){
  DentRobot::containerElevator->Run(0.0f);
}
void ContainerRaise::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

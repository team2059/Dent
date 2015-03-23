#include "Raise.h"
#include "../../DentRobot.h"
#include "../../OI.h"
Raise::Raise(double timeout): Command("Raise"){
  SetTimeout(timeout);
}
void Raise::Initialize(){
}
void Raise::Execute(){
  DentRobot::elevator->Run(1.0);
}
bool Raise::IsFinished(){
  //if(!DentRobot::elevator->GetElevatorMiddle()){
  //  DentRobot::elevator->stoppedAtSensor = true;
  //}
  //if((DentRobot::elevator->stoppedAtSensor)){
  //  printf("Stopped at the middle sensor\n");
  //  DentRobot::elevator->stoppedAtSensor = false;
  //  return true;
  //}else if(!DentRobot::elevator->GetElevatorTop()){
  if(!DentRobot::elevator->GetElevatorTop()||!DentRobot::elevator->GetElevatorMiddle()||IsTimedOut()){
    printf("Robot stopped raising. Sensor based? %d\n", !DentRobot::elevator->GetElevatorTop()||!DentRobot::elevator->GetElevatorMiddle());
    return true;
  }else{
    return false;
  }
}
void Raise::End(){
  // If the elevator is at the top
  if(DentRobot::elevator->GetElevatorTop()){
    DentRobot::elevator->SetUseEncoder(true);
  }
  DentRobot::elevator->Run(0.0f);
}
void Raise::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

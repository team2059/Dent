#include "Raise.h"
#include "../../DentRobot.h"
#include "../../OI.h"
Raise::Raise() : Command("Raise"){
}
void Raise::Initialize(){
  SetTimeout(3.0);
}
void Raise::Execute(){
  DentRobot::elevator->Run(1.0);
}
bool Raise::IsFinished(){
  if(!DentRobot::elevator->GetElevatorMiddle()){
    DentRobot::elevator->stoppedAtSensor=true;
  }
  if ((DentRobot::elevator->stoppedAtSensor)){
    printf("Stopped at the middle sensor\n");
    DentRobot::elevator->stoppedAtSensor=false;
    return true;
  }else if (!DentRobot::elevator->GetElevatorTop()) {
    printf("Stopping at the top sensor\n");
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

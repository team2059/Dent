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
  if (!DentRobot::elevator->GetElevatorTop()||IsTimedOut()){
    printf("Robot stoped raising. Sensor based? %d\n", !DentRobot::elevator->GetElevatorTop());
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

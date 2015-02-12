#include "Lower.h"
#include "../../DentRobot.h"
#include "../../OI.h"
Lower::Lower() : Command("Lower"){
}
void Lower::Initialize(){
  SetTimeout(2.5);
}
void Lower::Execute(){
  DentRobot::elevator->Run(-1.0);
}
bool Lower::IsFinished(){
  if (!DentRobot::elevator->GetElevatorBottom()||IsTimedOut()){
    printf("Robot stoped lowering. Sensor based? %d\n", !DentRobot::elevator->GetElevatorBottom());
    return true;
  }else{
    return false;
  }
}
void Lower::End(){
  DentRobot::elevator->Run(0.0f);
}
void Lower::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

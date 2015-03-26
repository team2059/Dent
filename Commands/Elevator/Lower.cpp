#include "Lower.h"
#include "../../DentRobot.h"
#include "../../OI.h"
Lower::Lower(double timeout, bool useSoftLimits): Command("Lower"){
  SetTimeout(timeout);
  softLimits=useSoftLimits;
}
void Lower::Initialize(){
}
void Lower::Execute(){
  DentRobot::elevator->Run(-1.0);
}
bool Lower::IsFinished(){
  if(softLimits){
    if(!DentRobot::elevator->GetElevatorBottom()){
      return true;
    }
  }
  if(IsTimedOut()){
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

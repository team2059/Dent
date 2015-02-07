#include "Lower.h"
#include "../../DentRobot.h"
#include "../../OI.h"
Lower::Lower() : Command("Lower"){
}
void Lower::Initialize(){
  SetTimeout(2.0);
}
void Lower::Execute(){
  DentRobot::elevator->Run((-DentRobot::oi->GetLeftStick()->GetRawAxis(3)+1.0)/2);
}
bool Lower::IsFinished(){
  if (DentRobot::elevator->GetElevatorBottom()||IsTimedOut()){
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

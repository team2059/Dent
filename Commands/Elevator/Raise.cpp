#include "Raise.h"
#include "../../DentRobot.h"
#include "../../OI.h"
Raise::Raise() : Command("Raise"){
}
void Raise::Initialize(){
  SetTimeout(2.0);
}
void Raise::Execute(){
  DentRobot::elevator->Run(-(-DentRobot::oi->GetLeftStick()->GetRawAxis(3)+1.0)/2);
}
bool Raise::IsFinished(){
  if (DentRobot::elevator->GetElevatorTop()||IsTimedOut()){
    return true;
  }else{
    return false;
  }
}
void Raise::End(){
  DentRobot::elevator->Run(0.0f);
}
void Raise::Interrupted(){
  End();
}
// vim: ts2:sw=2:et

#include "Lower.h"
#include "../../DentRobot.h"
Lower::Lower() : Command("Lower"){
}
void Lower::Initialize(){
}
void Lower::Execute(){
  DentRobot::elevator->Run((-DentRobot::oi->GetLeftStick()->GetRawAxis(3)+1.0)/2);
}
bool Lower::IsFinished(){
  return !DentRobot::dio->Get(DentRobot::dio->ELEVATORBOTTOM);
}
void Lower::End(){
  DentRobot::elevator->Run(0.0f);
}
void Lower::Interrupted(){
  End();
}

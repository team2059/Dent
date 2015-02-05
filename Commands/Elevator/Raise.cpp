#include "Raise.h"
#include "../../DentRobot.h"
#include "../../OI.h"
Raise::Raise(){
}
void Raise::Initialize(){
}
void Raise::Execute(){
  DentRobot::elevator->Run(-(-DentRobot::oi->GetLeftStick()->GetRawAxis(3)+1.0)/2);
}
bool Raise::IsFinished(){
  return false;
}
void Raise::End(){
  DentRobot::elevator->Run(0.0f);
}
void Raise::Interrupted(){
  End();
}

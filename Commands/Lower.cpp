#include "Lower.h"
#include "../DentRobot.h"
Lower::Lower() : Command("Lower"){
}
void Lower::Initialize(){
}
void Lower::Execute(){
  DentRobot::elevator->Run(-0.4f);
}
bool Lower::IsFinished(){
  // 0.1f is a placeholder for the min elevator value
  return DentRobot::elevator->GetPotValue()>=0.1f;
}
void Lower::End(){
  DentRobot::elevator->Run(0.0f);
}
void Lower::Interrupted(){
  End();
}

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
  return false;
}
void Lower::End(){
  DentRobot::elevator->Run(0.0f);
}
void Lower::Interrupted(){
  End();
}

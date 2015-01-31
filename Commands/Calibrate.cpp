#include "Calibrate.h"
#include "../DentRobot.h"
Calibrate::Calibrate() : Command("Calibrate"){
}
void Calibrate::Initialize(){
}
void Calibrate::Execute(){
  DentRobot::elevator->Run(-0.4f);
}
bool Calibrate::IsFinished(){
  return DentRobot::elevator->GetPotValue()>=0.1f;
}
void Calibrate::End(){
  DentRobot::elevator->Run(0.0f);
}
void Calibrate::Interrupted(){
  End();
}

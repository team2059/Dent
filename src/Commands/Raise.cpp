#include "Raise.h"
#include "../DentRobot.h"
Raise::Raise(){
}
void Raise::Initialize(){
}
void Raise::Execute(){
  DentRobot::elevator->Run(0.4f);
}
bool Raise::IsFinished(){
  // 0.9f is a placeholder for the max elevator value
  return DentRobot::elevator->GetPotValue()>=0.9f;
}
void Raise::End(){
  DentRobot::elevator->Run(0.0f);
}
void Raise::Interrupted(){
  End();
}

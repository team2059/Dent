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
  return false;
}
void Raise::End(){
  DentRobot::elevator->Run(0.0f);
}
void Raise::Interrupted(){
  End();
}

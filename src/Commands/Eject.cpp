#include "Eject.h"
#include "../DentRobot.h"
Eject::Eject() : Command("Eject"){
  Requires(DentRobot::collector);
}
void Eject::Initialize(){
}
void Eject::Execute(){
  DentRobot::collector->Set(DentRobot::oi->GetLeftStick()->GetThrottle());
}
bool Eject::IsFinished(){
  return false;
}
void Eject::End(){
}
void Eject::Interrupted(){
}

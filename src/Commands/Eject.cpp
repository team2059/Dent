#include "Eject.h"
#include "../DentRobot.h"
Eject::Eject(){
}
void Eject::Initialize(){
}
void Eject::Execute(){
  DentRobot::collector->Set(oi->GetLeftStick()->GetThrottle());
}
bool Eject::IsFinished(){
  return false;
}
void Eject::End(){

}
void Eject::Interrupted(){
}

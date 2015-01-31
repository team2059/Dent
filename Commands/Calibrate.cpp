#include "Calibrate.h"
#include "../DentRobot.h"
// Lowers elevator until it hits the limit switch then sets the height of the elevator to the height of the limit switches
Calibrate::Calibrate() : Command("Calibrate"){
}
void Calibrate::Initialize(){
}
void Calibrate::Execute(){
  // Lower collector until End()
  DentRobot::elevator->Run(-0.4f);
}
bool Calibrate::IsFinished(){
  if(DentRobot::dio->Get(DIO::ELEVATORBOTTOM)){
    // 0.99 is a placeholder for the height of the limit switches
    DentRobot::elevator->SetHeight(0.99);
    return true;
  }
  return false;
}
void Calibrate::End(){
  DentRobot::elevator->Run(0.0f);
}
void Calibrate::Interrupted(){
  End();
}

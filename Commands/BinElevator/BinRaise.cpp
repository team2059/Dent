#include "BinRaise.h"
#include "../../DentRobot.h"
#include "../../OI.h"
BinRaise::BinRaise(double timeout): Command("BinRaise"){
  SetTimeout(timeout);
}
void BinRaise::Initialize(){
}
void BinRaise::Execute(){
  DentRobot::binElevator->Run(1.0);
}
bool BinRaise::IsFinished(){
  if(/*!DentRobot::binElevator->GetElevatorTop()||*/IsTimedOut()){
    printf("Robot stoped raising. Sensor based? %d\n", !DentRobot::binElevator->GetElevatorTop());
    return true;
  }else{
    return false;
  }
}
void BinRaise::End(){
  DentRobot::binElevator->Run(0.0f);
}
void BinRaise::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

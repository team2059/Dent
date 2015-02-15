#include "BinLower.h"
#include "../../DentRobot.h"
#include "../../OI.h"
BinLower::BinLower() : Command("BinLower"){
}
void BinLower::Initialize(){
  SetTimeout(2.5);
}
void BinLower::Execute(){
  DentRobot::binElevator->Run(-1.0);
}
bool BinLower::IsFinished(){
  if (/*!DentRobot::binElevator->GetElevatorBottom()||*/IsTimedOut()){
    printf("Robot stoped BinLowering. Sensor based? %d\n", !DentRobot::binElevator->GetElevatorBottom());
    return true;
  }else{
    return false;
  }
}
void BinLower::End(){
  DentRobot::binElevator->Run(0.0f);
}
void BinLower::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

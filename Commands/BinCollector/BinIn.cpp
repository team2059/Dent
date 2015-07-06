#include "BinIn.h"
#include "../../DentRobot.h"
#include "../../OI.h"
BinIn::BinIn(float timeout): Command("BinIn"){
  SetTimeout(timeout);
}
void BinIn::Initialize(){
}
void BinIn::Execute(){
  DentRobot::binCollector->MoveArms(0.75);
}
bool BinIn::IsFinished(){
  if(IsTimedOut()){
    printf("Robot stopped collecting bin.\n");
    return true;
  }else{
    return false;
  }
}
void BinIn::End(){
  DentRobot::binCollector->MoveArms(0.0);
}
void BinIn::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

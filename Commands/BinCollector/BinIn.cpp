#include "BinIn.h"
#include "../../DentRobot.h"
#include "../../OI.h"
BinIn::BinIn(float timeout): Command("BinIn"){
  SetTimeout(timeout);
}
void BinIn::Initialize(){
}
void BinIn::Execute(){
  DentRobot::binCollector->Set(0.75);
  End();
}
bool BinIn::IsFinished(){
  if(IsTimedOut()){
    printf("Robot stoped collecting bin.\n");
    return true;
  }else{
    return false;
  }
}
void BinIn::End(){
}
void BinIn::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

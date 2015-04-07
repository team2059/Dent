#include "BinOut.h"
#include "../../DentRobot.h"
#include "../../OI.h"
BinOut::BinOut(double timeout): Command("BinOut"){
  SetTimeout(timeout);
}
void BinOut::Initialize(){
}
void BinOut::Execute(){
  DentRobot::binCollector->Set(0.1);
  End();
}
bool BinOut::IsFinished(){
  if(IsTimedOut()){
    printf("Robot stoped ejecting bin.\n");
    return true;
  }else{
    return false;
  }
}
void BinOut::End(){
}
void BinOut::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

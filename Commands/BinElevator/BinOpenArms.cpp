#include "BinOpenArms.h"
#include "../../DentRobot.h"
#include "../../OI.h"
BinOpenArms::BinOpenArms() : Command("BinOpenArms"){
}
void BinOpenArms::Initialize(){
  //Should never need to use this
  SetTimeout(0.5);
}
void BinOpenArms::Execute(){
  DentRobot::pneumatics->SetOpen(true);
}
bool BinOpenArms::IsFinished(){
  return true;
}
void BinOpenArms::End(){
}
void BinOpenArms::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

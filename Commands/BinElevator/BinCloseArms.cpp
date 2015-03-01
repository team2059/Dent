#include "BinCloseArms.h"
#include "../../DentRobot.h"
#include "../../OI.h"
BinCloseArms::BinCloseArms() : Command("BinCloseArms"){
}
void BinCloseArms::Initialize(){
  SetTimeout(0.5);
}
void BinCloseArms::Execute(){
  DentRobot::pneumatics->SetOpen(false);
}
bool BinCloseArms::IsFinished(){
  return true;
}
void BinCloseArms::End(){
}
void BinCloseArms::Interrupted(){
  End();
}
// vim: ts=2:sw=2:et

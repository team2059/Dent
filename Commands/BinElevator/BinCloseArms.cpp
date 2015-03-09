#include "BinCloseArms.h"
#include "../../DentRobot.h"
#include "../../OI.h"
BinCloseArms::BinCloseArms(double timeout): Command("BinCloseArms"){
  SetTimeout(timeout);
}
void BinCloseArms::Initialize(){
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

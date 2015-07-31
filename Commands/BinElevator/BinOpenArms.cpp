#include "BinOpenArms.h"
#include "../../DentRobot.h"
#include "../../OI.h"
BinOpenArms::BinOpenArms(double timeout): Command("BinOpenArms") {
  SetTimeout(timeout);
}
void BinOpenArms::Initialize() {
}
void BinOpenArms::Execute() {
  DentRobot::pneumatics->SetOpen(true);
}
bool BinOpenArms::IsFinished() {
  return true;
}
void BinOpenArms::End() {
}
void BinOpenArms::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et

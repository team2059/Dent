#include "BinCloseClaw.h"
#include "../../DentRobot.h"
#include "../../OI.h"
BinCloseClaw::BinCloseClaw(double timeout): Command("BinCloseClaw") {
  SetTimeout(timeout);
}
void BinCloseClaw::Initialize() {}
void BinCloseClaw::Execute() {
  DentRobot::pneumatics->SetClawOpen(false);
}
bool BinCloseClaw::IsFinished() {
  return true;
}
void BinCloseClaw::End() {}
void BinCloseClaw::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et

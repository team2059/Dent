#include "BinOpenClaw.h"
#include "../../DentRobot.h"
#include "../../OI.h"
BinOpenClaw::BinOpenClaw(double timeout): Command("BinOpenClaw") {
  SetTimeout(timeout);
}
void BinOpenClaw::Initialize() {}
void BinOpenClaw::Execute() {
  DentRobot::pneumatics->SetClawOpen(true);
}
bool BinOpenClaw::IsFinished() {
  return true;
}
void BinOpenClaw::End() {}
void BinOpenClaw::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et

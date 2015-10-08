#include "CloseArm.h"
#include "../../DentRobot.h"
#include "../../OI.h"
CloseArm::CloseArm(double timeout): Command("CloseArm") {
  SetTimeout(timeout);
}
void CloseArm::Initialize() {}
void CloseArm::Execute() {
  DentRobot::pneumatics->SetElevatorArmOpen(false);
}
bool CloseArm::IsFinished() {
  return true;
}
void CloseArm::End() {}
void CloseArm::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et

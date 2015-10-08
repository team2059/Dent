#include "OpenArm.h"
#include "../../DentRobot.h"
#include "../../OI.h"
OpenArm::OpenArm(double timeout): Command("OpenArm") {
  SetTimeout(timeout);
}
void OpenArm::Initialize() {}
void OpenArm::Execute() {
  DentRobot::pneumatics->SetElevatorArmOpen(true);
}
bool OpenArm::IsFinished() {
  return true;
}
void OpenArm::End() {}
void OpenArm::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et

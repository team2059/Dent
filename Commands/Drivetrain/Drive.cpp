#include "Drive.h"
#include "../../DentRobot.h"
Drive::Drive(): Command("Drive") {
  Requires(DentRobot::drivetrain);
}
void Drive::Initialize() {}
void Drive::Execute() {
  float x, y, z;
  x = -DentRobot::oi->GetLeftStick()->GetRawAxis(0);
  y = DentRobot::oi->GetLeftStick()->GetRawAxis(1);
  z = DentRobot::oi->GetLeftStick()->GetRawAxis(2);
  //X axis, Y axis, Z axis, sensitivity, speed threshold (usually throttle)
  if(DentRobot::oi->GetLeftStick()->GetRawButton(11)) {
    x = -x;
    y = -y;
  }
  DentRobot::drivetrain->DriveArcade(x, y, z, 0.9);
}
bool Drive::IsFinished() {
  return IsTimedOut();
}
void Drive::End() {}
void Drive::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et

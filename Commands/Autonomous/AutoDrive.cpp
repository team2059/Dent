#include "AutoDrive.h"
#include "../../DentRobot.h"
// Drive for a short while then stop. Just for testing
AutoDrive::AutoDrive(double duration, double xtmp, double ytmp, double ztmp, bool useGyro): Command("AutoDrive") {
  Requires(DentRobot::drivetrain);
  SetTimeout(duration);
  x = xtmp;
  y = ytmp;
  z = ztmp;
  gyro = useGyro;
}
void AutoDrive::Initialize() {
  DentRobot::drivetrain->ResetGyro();
}
void AutoDrive::Execute() {
  //X axis, Y axis, Z axis, sensitivity, speed threshold (usually throttle)
  DentRobot::drivetrain->DriveArcade(x, y, z, 0.9, gyro);
}
bool AutoDrive::IsFinished() {
  return IsTimedOut();
}
void AutoDrive::End() {
  DentRobot::drivetrain->DriveArcade(0.0, 0.0, 0.0, 0.9);
}
void AutoDrive::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et

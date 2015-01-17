#ifndef DENTROBOT_H
#define DENTROBOT_H
#include "WPILib.h"
#include "Commands/Drive.h"
#include "Commands/Collect.h"
#include "Commands/Eject.h"
#include "Commands/Raise.h"
#include "Commands/Lower.h"
class DentRobot: public IterativeRobot {
private:
  Command *driveCommand = NULL;
public:
  DentRobot();
  void RobotInit();
  void DisabledPeriodic();
  void AutonomousInit();
  void AutonomousPeriodic();
  void TeleopInit();
  void TeleopPeriodic();
  void TestPeriodic();
};
#endif
// vim: ts=2:sw=2:et

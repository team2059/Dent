#ifndef __HH_BASE_H__
#define __HH_BASE_H__
#include <WPILib.h>
#include <string>
#include "HHRobot.h"
//Because this is the first header to be included, classes need to be declared here
class HHRobot;
class HHBase : public IterativeRobot{
  private:
	HHRobot *hhbot;
  public:
    HHBase();
    void RobotInit();
    void DisabledInit();
    void AutonomousInit();
    void TeleopInit();
    void DisabledContinuous();
    void AutonomousContinuous();
    void TeleopContinuous();
    void DisabledPeriodic();
    void AutonomousPeriodic();
    void TeleopPeriodic();
    void Test();
};
#endif
// vim: ts=2:sw=2:et

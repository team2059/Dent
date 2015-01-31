#ifndef DENTROBOT_H
#define DENTROBOT_H
#include "WPILib.h"
#include "OI.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/DIO.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Collector.h"
#include "Subsystems/AirCompressor.h"
class DentRobot: public IterativeRobot {
private:
  Command *driveCommand = NULL;
public:
  static OI* oi;
  static Collector* collector;
  static Drivetrain* drivetrain;
  static Elevator* elevator;
  static DIO* dio;
  static AirCompressor* airCompressor;
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

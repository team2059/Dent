#ifndef DENTROBOT_H
#define DENTROBOT_H
#include "WPILib.h"
#include "OI.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/BinElevator.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Collector.h"
#include "Commands/Autonomous/Autonomous.h"
class DentRobot: public IterativeRobot {
  private:
    Command *driveCommand = NULL;
  public:
    DentRobot();
    static OI* oi;
    static Collector* collector;
    static Drivetrain* drivetrain;
    static Elevator* elevator;
    static BinElevator* binElevator;
    static CommandGroup* aut;
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
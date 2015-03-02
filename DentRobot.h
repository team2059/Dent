#ifndef DENTROBOT_H
#define DENTROBOT_H
#include "WPILib.h"
#include "OI.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/BinElevator.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Collector.h"
#include "Subsystems/Pneumatics.h"
#include "Commands/Autonomous/Autonomous.h"
/**
 * @brief The Hitchhikers 2015 robot, Dent
 *
 * Features a 4-motor collector, 4-motor mecanum drivetrain, two one-motor elevators
 */
class DentRobot: public IterativeRobot {
  private:
    /**
     * @brief The default driving command
     */
    Command *driveCommand = NULL;
  public:
    /**
     * @brief Constructs DentRobot
     */
    DentRobot();
    /**
     * @brief The 2-joystick OI
     */
    static OI* oi;
    /**
     * @brief The 4-motor Collctor
     */
    static Collector* collector;
    /**
     * @brief The 4-motor mechanum Drivetrain
     */
    static Drivetrain* drivetrain;
    /**
     * @brief The main one-motor Elevator for lifting totes
     */
    static Elevator* elevator;
    /**
     * @brief The back one-motor Elevator for lifting totes or bins
     */
    static BinElevator* binElevator;
    /**
     * @brief The Pneumatics system (UNUSED)
     */
    static Pneumatics* pneumatics;
    /**
     * @brief The Autonomous command
     */
    static CommandGroup* aut;
    /**
     * @brief Initializes the robot
     */
    void RobotInit();
    /**
     * @brief Periodically run when disabled
     */
    void DisabledPeriodic();
    /**
     * @brief Initializes the autonomous period
     */
    void AutonomousInit();
    /**
     * @brief Periodically run when enabled in autonomous
     */
    void AutonomousPeriodic();
    /**
     * @brief Initializes the teleop period
     */
    void TeleopInit();
    /**
     * @brief Periodically run when enabled in autonomous
     */
    void TeleopPeriodic();
    /**
     * @brief Periodically run when enabled in test mode
     */
    void TestPeriodic();
};
#endif
// vim: ts=2:sw=2:et

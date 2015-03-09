#ifndef AUTODRIVE_H
#define AUTODRIVE_H

#include "Commands/Command.h"
#include "../../DentRobot.h"
#include "../../DentRobot.h"
#include "WPILib.h"

/**
 * @brief Drives the robot without a joystick
 *
 * Drives the robot given a timeout and joystick values
 */
class AutoDrive: public Command{
  private:
    double x, //<! The x value of the simulated joystick value
           y; //<! The y value of the simulated joystick value
  public:
    /**
     * @brief Constructs AutoDrive
     *
     * @param duration Timeout in seconds
     * @param xtmp Joystick x value (default: 0.0)
     * @param ytmp Joystick y value (default: 0.75)
     */
    AutoDrive(double duration, double xtmp = 0.0, double ytmp = -0.75);
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Drives the robot
     */
    void Execute();
    /**
     * @brief Checks if the command is finished
     *
     * @return True only if the timeout was reached
     */
    bool IsFinished();
    /**
     * @brief Sets the drivetrain to stop
     */
    void End();
    /**
     * @brief Calls End()
     */
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

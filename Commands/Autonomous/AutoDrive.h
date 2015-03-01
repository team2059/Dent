#ifndef AUTODRIVE_H
#define AUTODRIVE_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

/**
 * @brief Drives the robot without a joystick
 *
 * Drives the robot given a timeout and joystick values
 */
class AutoDrive: public Command{
  private:
    double x, y;
  public:
    /**
     * @brief Constructs AutoDrive
     *
     * @param double Timeout in seconds
     * @param double Joystick x value (default: 0.0)
     * @param double Joystick y value (default: 0.75)
     */
    AutoDrive(double, double, double);
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

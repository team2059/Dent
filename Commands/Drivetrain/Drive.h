#ifndef DRIVE_H
#define DRIVE_H

#include "Commands/Command.h"
#include "../../DentRobot.h"
#include "../../DentRobot.h"
#include "WPILib.h"

/**
 * @brief Drives the robot with a joystick
 *
 * Uses mechanum drive
 */
class Drive: public Command{
  public:
    /**
     * @brief Constructs Drive
     */
    Drive();
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Drives the robot with joysticks from OI
     */
    void Execute();
    /**
     * @brief Checks if the command is finished
     *
     * @return False
     */
    bool IsFinished();
    /**
     * @brief Ends the command
     */
    void End();
    /**
     * @brief Calls End()
     */
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

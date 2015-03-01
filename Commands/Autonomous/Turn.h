#ifndef TURN_H
#define TURN_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

/**
 * @brief Turns the robot
 *
 * Turns the robot until a timeout is reached
 */
class Turn: public Command{
  private:
    int degrees;
  public:
    /**
     * @brief Constructs Turn
     *
     * @param double Timeout in seconds
     */
    Turn(double);
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Turns the robot
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

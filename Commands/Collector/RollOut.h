#ifndef ROLLOUT_H
#define ROLLOUT_H

#include "Commands/Command.h"
#include "../../DentRobot.h"
#include "../../DentRobot.h"
#include "WPILib.h"

/**
 * @brief Rolls collector motors out until a timeout is reached
 */
class RollOut: public Command{
  public:
    /**
     * @brief Constructs RollOut
     *
     * @param timeout The timeout
     */
    RollOut(double timeout=2.0);
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Rolls the four collector motors out
     */
    void Execute();
    /**
     * @brief Checks if the command is finished
     *
     * @return True only if the timeout was reached
     */
    bool IsFinished();
    /**
     * @brief Sets the collector to stop
     */
    void End();
    /**
     * @brief Calls End()
     */
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

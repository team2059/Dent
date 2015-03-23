#ifndef RAISE_H
#define RAISE_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Raises the elevator until a timeout is reached
 */
class Raise: public Command{
  public:
    /**
     * @brief Constructs Raise
     *
     * @param timeout Timeout in seconds (default: 3.5)
     */
    Raise(double timeout = 3.5);
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Raises the elevator at 1.0 power
     */
    void Execute();
    /**
     * @brief Checks if the command is finished
     *
     * @return True if the timeout was reached or if the top elevator was triggered or if the middle elevator is triggered
     */
    bool IsFinished();
    /**
     * @brief Sets the elevator to stop
     */
    void End();
    /**
     * @brief Calls End()
     */
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

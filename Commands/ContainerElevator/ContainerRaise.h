#ifndef CONTAINER_RAISE_H
#define CONTAINER_RAISE_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Raises the container elevator until a timeout is reached
 */
class ContainerRaise: public Command{
  private:
  public:
    /**
     * @brief Constructs ContainerRaise
     *
     * @param timeout Timeout in seconds
     */
    ContainerRaise(double timeout);
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Raises the container elevator at 1.0 power
     */
    void Execute();
    /**
     * @brief Checks if the command is finished
     *
     * @return True only if the timeout was reached
     */
    bool IsFinished();
    /**
     * @brief Sets the container elevator to stop
     */
    void End();
    /**
     * @brief Calls End()
     */
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

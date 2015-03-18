#ifndef CONTAINER_LOWER_H
#define CONTAINER_LOWER_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Lowers the container elevator until a timeout is reached
 */
class ContainerLower: public Command{
  private:
  public:
    /**
     * @brief Constructs ContainerLower
     *
     * @param timeout The timeout
     */
    ContainerLower(float timeout);
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Lowers the container elevator at -1.0 power
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

#ifndef CONTAINER_LOWER_H
#define CONTAINER_LOWER_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Lowers the CONTAINER_ elevator until a timeout is reached
 */
class CONTAINER_Lower: public Command{
  private:
  public:
    /**
     * @brief Constructs CONTAINER_Lower
     *
     * @param float The timeout
     */
    CONTAINER_Lower(float timeout);
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Lowers the CONTAINER_ elevator at -1.0 power
     */
    void Execute();
    /**
     * @brief Checks if the command is finished
     *
     * @return True only if the timeout was reached
     */
    bool IsFinished();
    /**
     * @brief Sets the CONTAINER_ elevator to stop
     */
    void End();
    /**
     * @brief Calls End()
     */
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

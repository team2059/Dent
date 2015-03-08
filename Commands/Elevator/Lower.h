#ifndef LOWER_H
#define LOWER_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Lowers the elevator until a timeout is reached
 */
class Lower: public Command{
  public:
    Lower(double timeout=3.0);
    /**
     * @brief Constructs Lower
     */
    Lower();
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Lowers the elevator at -1.0 power
     */
    void Execute();
    /**
     * @brief Checks if the command is finished
     *
     * @return True if the timeout was reached or if the bottom elevator sensor was triggered
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

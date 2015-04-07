#ifndef BinIn_H
#define BinIn_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Lowers the bin collector until a timeout is reached
 */
class BinIn: public Command{
  public:
    /**
     * @brief Constructs BinIn
     *
     * @param timeout Timeout in seconds
     */
    BinIn(float timeout);
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Lowers the bin collector at -1.0 power
     */
    void Execute();
    /**
     * @brief Checks if the command is finished
     *
     * @return True only if the timeout was reached
     */
    bool IsFinished();
    /**
     * @brief Sets the bin collector to stop
     */
    void End();
    /**
     * @brief Calls End()
     */
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

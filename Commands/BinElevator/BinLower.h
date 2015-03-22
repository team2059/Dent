#ifndef BINLOWER_H
#define BINLOWER_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Lowers the bin elevator until a timeout is reached
 */
class BinLower: public Command{
  public:
    /**
     * @brief Constructs BinLower
     *
     * @param timeout The timeout
     */
    BinLower(float timeout);
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Lowers the bin elevator at -1.0 power
     */
    void Execute();
    /**
     * @brief Checks if the command is finished
     *
     * @return True only if the timeout was reached
     */
    bool IsFinished();
    /**
     * @brief Sets the bin elevator to stop
     */
    void End();
    /**
     * @brief Calls End()
     */
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

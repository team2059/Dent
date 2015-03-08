#ifndef BINCLOSEARMS_H
#define BINCLOSEARMS_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Closes BinElevatorArms (NOT USED)
 *
 * Sets the solenoid to close the arms of the BinElevator
 */
class BinCloseArms: public Command{
  public:
    BinCloseArms(double timeout = 0.5);
    /**
     * @brief Constructs BinCloseArms
     */
    BinCloseArms();
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Sets the solenoid to close the arms
     */
    void Execute();
    /**
     * @brief Returns true to prevent solenoid damage
     *
     * @return True
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

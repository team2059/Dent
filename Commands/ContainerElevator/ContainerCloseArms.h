#ifndef CONTAINER_CLOSEARMS_H
#define CONTAINER_CLOSEARMS_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Closes CONTAINER_ElevatorArms (NOT USED)
 *
 * Sets the solenoid to close the arms of the CONTAINER_Elevator
 */
class CONTAINER_CloseArms: public Command{
  public:
    /**
     * @brief Constructs CONTAINER_CloseArms
     *
     * @param timeout The timeout
     */
    CONTAINER_CloseArms(double timeout = 0.5);
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

#ifndef CONTAINER_CLOSEARMS_H
#define CONTAINER_CLOSEARMS_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Closes ContainerElevatorArms (NOT USED)
 *
 * Sets the solenoid to close the arms of the ContainerElevator
 */
class ContainerCloseArms: public Command{
  public:
    /**
     * @brief Constructs ContainerCloseArms
     *
     * @param timeout The timeout
     */
    ContainerCloseArms(double timeout = 0.5);
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

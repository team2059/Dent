#ifndef CONTAINER_OPENARMS_H
#define CONTAINER_OPENARMS_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Opens container arms (unused)
 */
class ContainerOpenArms: public Command{
  public:
    /**
     * @brief Constructs ContainerOpenArms
     *
     * @param timeout The timeout
     */
    ContainerOpenArms(double timeout);
    /**
     * @brief Constructs ContainerOpenArms
     */
    ContainerOpenArms();
    /**
     * @brief Initializes the class
     */
    void Initialize();
    /**
     * @brief Sets the solenoid to open the arms
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

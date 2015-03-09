#ifndef BINOPENARMS_H
#define BINOPENARMS_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Opens bin arms (unused)
 */
class BinOpenArms: public Command{
  public:
    /**
     * @brief Constructs BinOpenArms
     *
     * @param double The timeout
     */
    BinOpenArms(double);
    /**
     * @brief Constructs BinOpenArms
     */
    BinOpenArms();
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

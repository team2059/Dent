#ifndef BINCLOSECLAW_H
#define BINCLOSECLAW_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Closes BinElevatorArms
 */
class BinCloseClaw: public Command {
 public:
  /**
   * @brief Constructs BinCloseClaw
   *
   * @param timeout Timeout in seconds (default: 0.5)
   */
  BinCloseClaw(double timeout = 0.5);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Sets the solenoid to close the claw
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

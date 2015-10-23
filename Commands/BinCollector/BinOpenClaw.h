#ifndef BINOPENCLAW_H
#define BINOPENCLAW_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Closes BinElevatorArms
 */
class BinOpenClaw: public Command {
 public:
  /**
   * @brief Constructs BinOpenClaw
   *
   * @param timeout Timeout in seconds (default: 0.5)
   */
  BinOpenClaw(double timeout = 0.5);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Sets the solenoid to open the claw
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

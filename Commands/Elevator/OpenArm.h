#ifndef OPENARM_H
#define OPENARM_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Opens bin retaining arm
 */
class OpenArm: public Command {
 public:
  /**
   * @brief Constructs OpenArm
   *
   * @param timeout Timeout in seconds
   */
  OpenArm(double timeout);
  /**
   * @brief Constructs OpenArm
   */
  OpenArm();
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Sets the solenoid to open the arm
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

#ifndef CLOSEARM_H
#define CLOSEARM_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Closes bin retaining arm
 */
class CloseArm: public Command {
 public:
  /**
   * @brief Constructs CloseArm
   *
   * @param timeout Timeout in seconds
   */
  CloseArm(double timeout);
  /**
   * @brief Constructs CloseArm
   */
  CloseArm();
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Sets the solenoid to close the arm
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

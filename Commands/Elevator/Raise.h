#ifndef RAISE_H
#define RAISE_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Raises the elevator until a timeout is reached
 */
class Raise: public Command {
 private:
  bool softLimits; //<!Enabled/Disables soft limits
  double speed; //<! speed to lower the elevator
 public:
  /**
   * @brief Constructs Raise
   *
   * @param timeout Timeout in seconds (default: 3.5)
   *
   * @param useSoftLimits Enables/Disables soft limits via hall effect sensors (default: true)
   *
   * @param liftSpeed Speed at which to raise the elevator
   */
  Raise(double timeout = 3.5, bool useSoftLimits = true, double liftSpeed=0);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Raises the elevator at 1.0 power
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   *
   * @return True if the timeout was reached
   */
  bool IsFinished();
  /**
   * @brief Sets the elevator to stop
   */
  void End();
  /**
   * @brief Calls End()
   */
  void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

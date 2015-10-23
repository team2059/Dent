#ifndef LOWER_H
#define LOWER_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Lowers the elevator until a timeout is reached
 */
class Lower: public Command {
 private:
  bool softLimits; //<! Enables/Disables hall effect sensors
  double speed; //<! speed to lower the elevator
 public:
  /**
   * @brief Constructs Lower
   *
   * @param timeout Timeout in seconds (default: 3.0)
   *
   * @param useSoftLimits Enables/Disables soft limits via hall effect sensors (default: true)
   *
   * @param liftSpeed Speed at which to lower the lift
   */
  Lower(double timeout = 3.0, bool useSoftLimits = true, double liftSpeed=1);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Lowers the elevator at -1.0 power
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

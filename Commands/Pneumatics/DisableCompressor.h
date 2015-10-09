#ifndef DISABLECOMPRESSOR_H
#define DISABLECOMPRESSOR_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief DisableCompressors the elevator until a timeout is reached
 */
class DisableCompressor: public Command {
 private:
  bool softLimits;
  double speed;
 public:
  /**
   * @brief Constructs DisableCompressor
   *
   * @param timeout Timeout in seconds (default: 3.5)
   */
  DisableCompressor(double timeout = 3.5);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief DisableCompressors the elevator at 1.0 power
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   *
   * @return True if the timeout was reached or if the top elevator was triggered or if the middle elevator is triggered
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

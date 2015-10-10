#ifndef DISABLECOMPRESSOR_H
#define DISABLECOMPRESSOR_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief disable the compressor regardless of current psi
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
   * @brief DisableCompressors sets the compressor to disabled
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   *
   * @return True if the timeout was reached
   */
  bool IsFinished();
  /**
   * @brief required for command
   */
  void End();
  /**
   * @brief Calls End()
   */
  void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

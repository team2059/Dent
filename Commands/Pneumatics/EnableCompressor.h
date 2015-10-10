#ifndef ENABLECOMPRESSOR_H
#define ENABLECOMPRESSOR_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief allows the compressor to run if the system is within the psi threshold
 */
class EnableCompressor: public Command {
 private:
  bool softLimits;
  double speed;
 public:
  /**
   * @brief Constructs EnableCompressor
   *
   * @param timeout Timeout in seconds (default: 3.5)
   */
  EnableCompressor(double timeout = 3.5);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief EnableCompressors sets the compressor to enabled
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   *
   * @return True if the timeout was reached
   */
  bool IsFinished();
  /**
   * @brief required for the command
   */
  void End();
  /**
   * @brief Calls End()
   */
  void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

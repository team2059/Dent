#ifndef BinOut_H
#define BinOut_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Raises the bin collector until a timeout is reached
 */
class BinOut: public Command {
 public:
  /**
   * @brief Constructs BinOut
   *
   * @param timeout Timeout in seconds
   */
  BinOut(double timeout);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Raises the bin colector at 1.0 power
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   *
   * @return True only if the timeout was reached
   */
  bool IsFinished();
  /**
   * @brief Sets the bin colector to stop
   */
  void End();
  /**
   * @brief Calls End()
   */
  void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

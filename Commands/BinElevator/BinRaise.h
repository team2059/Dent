#ifndef BINRAISE_H
#define BINRAISE_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Raises the bin elevator until a timeout is reached
 */
class BinRaise: public Command {
 private:
 public:
  /**
   * @brief Constructs BinRaise
   *
   * @param timeout Timeout in seconds
   */
  BinRaise(double timeout);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Raises the bin elevator at 1.0 power
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   *
   * @return True only if the timeout was reached
   */
  bool IsFinished();
  /**
   * @brief Sets the bin elevator to stop
   */
  void End();
  /**
   * @brief Calls End()
   */
  void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

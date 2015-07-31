#ifndef ROLLIN_H
#define ROLLIN_H

#include "Commands/Command.h"
#include "../../DentRobot.h"
#include "../../DentRobot.h"
#include "WPILib.h"

/**
 * @brief Rolls collector motors in until a timeout is reached
 */
class RollIn: public Command {
 private:
  double rawSpeed; //<! Raw speed of the collector
 public:
  /**
   * @brief Constructs RollIn
   *
   * @param speed Speed to roll the collector
   */
  RollIn(double speed);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Rolls the four collector motors in
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   *
   * @return True only if the timeout was reached
   */
  bool IsFinished();
  /**
   * @brief Sets the collector to stop
   */
  void End();
  /**
   * @brief Calls End()
   */
  void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

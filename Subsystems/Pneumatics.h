#ifndef PNEUMATICS_H
#define PNEUMATICS_H

#include "WPILib.h"
/**
 * @brief Pneumatics on the robot
*
* For opening or closing the bin arms
 */
class Pneumatics: public Subsystem {
 private:
  Compressor *compressor; //<! Compressor
  Solenoid *solenoid1, //<! Solenoid 1
           *solenoid2, //<! Solenoid 2
           *solenoid3, //<! Solenoid 3
           *solenoid4; //<! Solenoid 4
  bool armState; //<! State of the arm
 public:
  /**
   * @brief Constructs Pneumatics
   */
  Pneumatics();
  /**
   * @brief No action
   */
  void InitDefaultCommand();
  /**
   * @brief Sets the state of the arms
   *
   * @param state State of the arms
   */
  void SetArmsOpen(bool state);
  /**
   * @brief Sets the state of the compressor
   *
   * @param state State of the compressor
   */
  void SetCompressorEnabled(bool state);
  /**
   * @brief Sets the state of the elevator arm
   *
   * @param state State of the arm
   */
  void SetElevatorArmOpen(bool state);
  /**
   * @brief Gets the state of the arms
   *
   * @return State of the arms
   */
  bool GetArmsOpen();
  /**
   * @brief Gets the state of the compressor
   *
   * @return State of the compressor
   */
  bool GetCompressorEnabled();

};
#endif
// vim: ts=2:sw=2:et

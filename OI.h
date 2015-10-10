#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Commands/Command.h"

/**
 * @brief Controls the robot with joysticks
 */
class OI {
 private:
  Joystick *leftStick,  //<! Left joystick
           *rightStick; //<! Right joystick
 public:
  /**
   * @brief Constructs OI
   */
  OI();
  /**
   * Raise command
   */
  /**
   * @brief Returns the right joystick
   *
   * @return The right joystick
   */
  Joystick* GetRightStick();
  /**
   * @brief Returns the left joystick
   *
   * @return The left joystick
   */
  Joystick* GetLeftStick();
  /**
   * @brief Returns the left joystick throttle
   *
   * @return The left joystick throttle
   */
  double GetLeftThrottle();
  /**
   * @brief Returns the right joystick throttle
   *
   * @return The right joystick throttle
   */
  double GetRightThrottle();
};
#endif
// vim: ts=2:sw=2:et

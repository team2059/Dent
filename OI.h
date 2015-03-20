#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "string"
#include "Commands/Command.h"

/**
 * @brief Controls the robot with joysticks
 */
class OI{
  private:
    Joystick *leftController, *rightStick;
    // Named Xbox buttons
    JoystickButton *leftA, *leftB, *leftX, *leftY, *leftLB, *leftRB, *leftBack, *leftStart, *leftLPress, *leftRPress;
  public:
    /**
     * @brief Constructs OI
     */
    OI();
    Command *raise, *lower, *binLower, *binRaise;
    float GetLeftAxis(std::string, std::string);
    bool GetLeftButton(std::string);
};
#endif
// vim: ts=2:sw=2:et

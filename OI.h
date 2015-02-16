#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Commands/Command.h"

class OI
{
  private:
    Joystick *leftStick, *rightStick;
  public:
    OI();
    Command *raise, *lower, *binLower, *binRaise;
    Joystick* GetRightStick();
    Joystick* GetLeftStick();
    double GetLeftThrottle();
    double GetRightThrottle();
};
#endif
// vim: ts=2:sw=2:et

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
    Joystick* GetRightStick();
    Joystick* GetLeftStick();
    Command *raise, *lower, *binLower, *binRaise;
};
#endif
// vim: ts=2:sw=2:et

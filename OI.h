#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
  private:
    Joystick *leftStick, *rightStick;
  public:
    OI();
    Joystick* GetRightStick();
    Joystick* GetLeftStick();
};
#endif

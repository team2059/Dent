#ifndef __ZAPHOD_ROBOT_H__
#define __ZAPHOD_ROBOT_H__
#include <WPILib.h>
#include "HHBase.h"
#include "hhlib/input/controller/Joystick.h"
class HHRobot{
  private:
    CANTalon *tmpMotor1;
    Extreme3dPro *joystick1;
  public:
    HHRobot();
    void Init();
    void Handler();
};
#endif
// vim: ts=2:sw=2:et

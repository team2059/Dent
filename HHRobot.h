#ifndef __ROBOT_H__
#define __ROBOT_H__
#include <WPILib.h>
#include "HHBase.h"
#include "classes/Collector.h"
#include "hhlib/input/controller/Joystick.h"
class HHRobot{
  private:
    RobotDrive *hhdrive;
    Gyro *gyro;
    DentCollector *collector;
    Extreme3dPro *driveStick;
  public:
    HHRobot();
    void Init();
    void Handler();
};
#endif
// vim: ts=2:sw=2:et

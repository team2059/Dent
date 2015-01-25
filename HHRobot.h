#ifndef __ZAPHOD_ROBOT_H__
#define __ZAPHOD_ROBOT_H__
#include <WPILib.h>
#include "HHBase.h"
#include "hhlib/input/controller/Joystick.h"
#include "hhlib/drive/MecanumDrive.h"
class HHRobot{
  private:
    Extreme3dPro *DriveStick;
    //CAN Devices
    Compressor *AirCompressor;
    PowerDistributionPanel *PowerDistPanel;
    MecanumDrive *RobotDrive;
  public:
    HHRobot();
    void Init();
    void Handler();
};
#endif
// vim: ts=2:sw=2:et

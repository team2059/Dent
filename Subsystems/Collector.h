#ifndef COLLECTOR_H
#define COLLECTOR_H

#include "WPILib.h"
class Collector: public Subsystem
{
  private:
    CANTalon *windowMotorLeft, *windowMotorRight, *collectorMotorLeft, *collectorMotorRight;
    DigitalInput *boxSwitch;
  public:
    Collector();
    void InitDefaultCommand();
    void MoveArms(float);
    void MoveRollers(float);
    bool ArmSensor();
    bool BoxCollected();
};
#endif

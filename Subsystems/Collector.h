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
    void MoveArms(double);
    void MoveRollers(double);
    bool ArmSensor();
    bool BoxCollected();
};
#endif

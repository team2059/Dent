#ifndef COLLECTOR_H
#define COLLECTOR_H

#include "WPILib.h"
class Collector: public Subsystem
{
  private:
    CANTalon *collectorMotorLeft, *collectorMotorBottom, *collectorMotorRamp, *collectorMotorRight;
  public:
    Collector();
    void InitDefaultCommand();
    void MoveRollers(double);
};
#endif
// vim: ts=2:sw=2:et

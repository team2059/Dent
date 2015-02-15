#ifndef COLLECTOR_H
#define COLLECTOR_H

#include "WPILib.h"
class Collector: public Subsystem
{
  private:
    CANTalon *collectorMotorLeft, *collectorMotorBottom, *collectorMotorRamp, *collectorMotorRight;
    AnalogInput *sonarAnalog;
    DigitalOutput *sonarDigital;
  public:
    Collector();
    void InitDefaultCommand();
    void MoveRollers(double);
    double GetSonarDistance();
};
#endif
// vim: ts=2:sw=2:et

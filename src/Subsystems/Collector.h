#ifndef COLLECTOR_H
#define COLLECTOR_H

#include "WPILib.h"
class Collector: public Subsystem
{
  private:
    Talon *motor1, *motor2;
  public:
    Collector();
    void InitDefaultCommand();
    void Set(float);
};
#endif

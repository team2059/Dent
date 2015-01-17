#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "WPILib.h"
#include "Commands/PIDSubsystem.h"
class Elevator: public PIDSubsystem
{
  private:
    AnalogPotentiometer *pot;
    Talon *leftMotor, *rightMotor;
    static constexpr double kP_real=4, kI_real=.0f, kP_simulation=18, kI_simulation=.2;
  public:
    Elevator();
    void InitDefaultCommand();
    float GetPotValue();
    void Run(double);
};
#endif

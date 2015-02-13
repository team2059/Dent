#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "WPILib.h"
#include "Commands/PIDSubsystem.h"
class Elevator{
  private:
    CANTalon *motor;
    Encoder *elevatorEncoder;
    static constexpr double kP_real=4, kI_real=.0f, kP_simulation=18, kI_simulation=.2;
    DigitalInput *elevatorBottom, *elevatorTop;
    bool useEncoder;
  public:
    Elevator();
    void InitDefaultCommand();
    void Run(double);
    void ResetEncoder();
    double GetHeight();
    bool GetElevatorTop();
    bool GetElevatorBottom();
    void SetUseEncoder(bool);
    bool GetUseEncoder();
};
#endif
// vim: ts=2:sw=2:et

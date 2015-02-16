#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "WPILib.h"
#include "Commands/PIDSubsystem.h"
class Elevator{
  private:
    CANTalon *motor;
    Encoder *elevatorEncoder;
    static constexpr double kP_real=4, kI_real=.0f, kP_simulation=18, kI_simulation=.2;
    DigitalInput *elevatorBottom, *elevatorMiddle, *elevatorTop;
    bool useEncoder;
  public:
    Elevator();
    bool stoppedAtSensor;
    void InitDefaultCommand();
    void Run(double);
    void ResetEncoder();
    double GetHeight();
    bool GetElevatorTop();
    bool GetElevatorMiddle();
    bool GetElevatorBottom();
    void SetUseEncoder(bool);
    bool GetUseEncoder();
};
#endif
// vim: ts=2:sw=2:et

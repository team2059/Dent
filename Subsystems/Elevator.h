#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "WPILib.h"
#include "Commands/PIDSubsystem.h"
class Elevator/*: public PIDSubsystem*/{
  private:
    CANTalon *motor;
    Encoder *elevatorEncoder;
    static constexpr double kP_real=4, kI_real=.0f, kP_simulation=18, kI_simulation=.2;
    double offset, height;
    DigitalInput *elevatorBottom, *elevatorTop;
  public:
    Elevator();
    void InitDefaultCommand();
    void Run(double);
    void SetOffset(double);
    void ResetEncoder();
    double GetHeight();
    bool GetElevatorTop();
    bool GetElevatorBottom();
};
#endif

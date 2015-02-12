#ifndef BINELEVATOR_H
#define BINELEVATOR_H

#include "WPILib.h"
#include "Commands/PIDSubsystem.h"
class BinElevator{
  private:
    CANTalon *motor;
    Encoder *elevatorEncoder;
    static constexpr double kP_real=4, kI_real=.0f, kP_simulation=18, kI_simulation=.2;
    DigitalInput *elevatorBottom, *elevatorTop;
  public:
    BinElevator();
    void InitDefaultCommand();
    void Run(double);
    void ResetEncoder();
    double GetHeight();
    bool GetElevatorTop();
    bool GetElevatorBottom();
};
#endif
// vim: ts=2:sw=2:et

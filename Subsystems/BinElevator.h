#ifndef BINELEVATOR_H
#define BINELEVATOR_H

#include "WPILib.h"
#include "Commands/PIDSubsystem.h"
class BinElevator{
  private:
    CANTalon *motor;
    Encoder *elevatorEncoder;
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

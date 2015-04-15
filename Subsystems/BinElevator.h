#ifndef BINELEVATOR_H
#define BINELEVATOR_H

#include "WPILib.h"
#include "Commands/PIDSubsystem.h"
/**
 * @brief Controls the bin elevator
 */
class BinElevator{
  private:
    CANTalon *leftMotor,//<! The left bin elevator motor
             *rightMotor; //<! The right bin elevator motor
    Encoder *elevatorEncoder; //<! The bin elevator encoder (unused)
    DigitalInput *elevatorBottom, //<! The bottom bin elevator sensor (unused)
                 *elevatorTop; //<! The top bin elevator sensor (unused)
  public:
    /**
     * @brief Constructs BinElevator
     */
    BinElevator();
    /**
     * @brief No action
     */
    void InitDefaultCommand();
    /**
     * @brief Runs the bin elevator
     *
     * @param power The power to run the bin elevator (-1.0 to 1.0)
     */
    void Run(double power);
    /**
     * @brief Sets the encoder value to 0 (unused)
     */
    void ResetEncoder();
    /**
     * @brief Gets the height of the bin elevator
     *
     * @return The height of the bin elevator
     */
    double GetHeight();
    /**
     * @brief Gets the status of the top sensor
     *
     * @return True if the sensor is activated
     */
    bool GetElevatorTop();
    /**
     * @brief Gets the status of the bottom sensor
     *
     * @return True if the sensor is activated
     */
    bool GetElevatorBottom();
};
#endif
// vim: ts=2:sw=2:et

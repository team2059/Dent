#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "WPILib.h"
/**
 * @brief The main elevator for lifting totes
 */
class Elevator{
  private:
    CANTalon *motor; //<! The elevator motor
    Encoder *elevatorEncoder; //<! The elevator encoder (unused)
    DigitalInput *elevatorBottom, //<! The bottom elevator sensor
                 *elevatorMiddle, //<! The middle elevator sensor
                 *elevatorTop; //<! The top elevator sensor
    bool useEncoder; //<! Use the elevator encoder (unused)
  public:
    /**
     * @brief Constructs Elevator
     */
    Elevator();
    /**
     * @brief No action
     */
    void InitDefaultCommand();
    /**
     * @brief Runs the elevator
     *
     * @param double The power to run the bin elevator (-1.0 to 1.0)
     */
    void Run(double);
    /**
     * @brief Sets the encoder value to 0 (unused)
     */
    void ResetEncoder();
    /**
     * @brief Gets the height of the elevator
     *
     * @return The hight of the elevator
     */
    double GetHeight();
    /**
     * @brief Gets the status of the top sensor
     *
     * @return True if the sensor is activated
     */
    bool GetElevatorTop();
    /**
     * @brief Gets the status of the middle sensor
     *
     * @return True if the sensor is activated
     */
    bool GetElevatorMiddle();
    /**
     * @brief Gets the status of the bottom sensor
     *
     * @return True if the sensor is activated
     */
    bool GetElevatorBottom();
    /**
     * @brief Use the elevator encoder (unused)
     *
     * @param bool State to use encoder
     */
    void SetUseEncoder(bool);
    /**
     * @brief Gets the state of useEncoder (unused)
     *
     * @return State of useEncoder
     */
    bool GetUseEncoder();
};
#endif
// vim: ts=2:sw=2:et

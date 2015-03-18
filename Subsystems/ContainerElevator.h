#ifndef CONTAINER_ELEVATOR_H
#define CONTAINER_ELEVATOR_H

#include "WPILib.h"
#include "Commands/PIDSubsystem.h"
/**
 * @brief Controls the container elevator
 */
class ContainerElevator{
  private:
    CANTalon *motor; //<! The container elevator motor
    Encoder *elevatorEncoder; //<! The container elevator encoder (unused)
    DigitalInput *elevatorBottom, //<! The bottom container elevator sensor (unused)
                 *elevatorTop; //<! The top container elevator sensor (unused)
  public:
    /**
     * @brief Constructs ContainerElevator
     */
    ContainerElevator();
    /**
     * @brief No action
     */
    void InitDefaultCommand();
    /**
     * @brief Runs the container elevator
     *
     * @param power The power to run the container elevator
     * 
     * Ranges from -1.0 to 1.0
     */
    void Run(double power);
    /**
     * @brief Sets the encoder value to 0 (unused)
     */
    void ResetEncoder();
    /**
     * @brief Gets the height of the container elevator
     *
     * @return The height of the container elevator
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

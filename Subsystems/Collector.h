#ifndef COLLECTOR_H
#define COLLECTOR_H

#include "WPILib.h"
/**
 * @brief Collects totes
 * 
 * Uses four motors, two on the sides, one on the bottom, and one on the ramp to collect and eject totes
 */
class Collector: public Subsystem{
  private:
    Victor *collectorMotorLeft,   //<! Left collector motor
             *collectorMotorBottom, //<! Bottom collector motor
             *collectorMotorRamp,   //<! Ramp collector motor
             *collectorMotorRight;  //<! Right collector motor
    /**
     * @brief Analog input for sonar (unused)
     */
    AnalogInput *sonarAnalog;
    /**
     * @brief Digital output for sonar (unused)
     */
    DigitalOutput *sonarDigital;
  public:
    /**
     * @brief Constructs Collector
     */
    Collector();
    /**
     * @brief No action
     */
    void InitDefaultCommand();
    /**
     * @brief Moves the collectors
     *
     * @param double The speed to run the collectors
     */
    void MoveRollers(double);
    /**
     * @brief Gets the distance of the sonar (unused)
     *
     * @return The sonar distance
     */
    double GetSonarDistance();
};
#endif
// vim: ts=2:sw=2:et

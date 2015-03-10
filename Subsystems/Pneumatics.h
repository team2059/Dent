#ifndef PNEUMATICS_H
#define PNEUMATICS_H

#include "WPILib.h"
/**
 * @brief Pneumatics on the robot (unused)
* 
* For opening or closing the container arms
 */
class Pneumatics: public Subsystem{
  private:
    Solenoid *solenoid1, //<! Solenoid 1
             *solenoid2; //<! Solenoid 3
  public:
    /**
     * @brief Constructs Pneumatics
     */
    Pneumatics();
    /**
     * @brief No action
     */
    void InitDefaultCommand();
    /**
     * @brief Sets the state of the arms
     *
     * @param bool State of the arms
     */
    void SetOpen(bool);
};
#endif
// vim: ts=2:sw=2:et

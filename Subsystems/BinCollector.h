#ifndef BinCollector_H
#define BinCollector_H

#include "WPILib.h"
/**
 * @brief Collects bins
 *
 * Collects bins with a servo
 */
class BinCollector: public Subsystem{
  private:
    CANTalon *leftBinCollectorMotor, //<<! Left bin collector motor
             *rightBinCollectorMotor; //<<! Right bin collector motor
  public:
    /**
     * @brief Constructs BinCollector
     */
    BinCollector();
    /**
     * @brief No action
     */
    void InitDefaultCommand();
    /**
     * @brief Moves bin collector arms at given speed
     *
     * @param speed the speed to move the bin collector arms
     */
    void MoveArms(double speed);
};
#endif
// vim: ts=2:sw=2:et

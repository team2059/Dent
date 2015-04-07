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
    Servo *binCollectorMotor; //<! BinCollector motor
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
     * @brief Sets the servo angle
     *
     * @param pos The angle of the servo (0.0 to 1.0)
     */
    void Set(double pos);
    /**
     * @brief Gets the servo angle
     *
     * @return The servo angle (0.0 to 1.0)
     */
    double Get();
};
#endif
// vim: ts=2:sw=2:et

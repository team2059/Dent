#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Commands/Command.h"

/**
 * @brief Controls the robot with joysticks
 */
class OI{
  private:
    Joystick *leftController, *rightController;
  public:
    /**
     * @brief Constructs OI
     */
    OI();
    Command *raise,    //!< Raise command
            *lower,    //!< Lower command
            *binLower, //!< BinLower command
            *binRaise; //!< BinRaise command
    /**
     * @brief Gets the value of a throttle on the left controller
     *
     * @param stick The stick to get. Can be "left" or "right"
     * @param axis The axis to get. Can be "x", "y", or "trigger"
     *
     * @return 
     */
    float GetLeftAxis(std::string stick, std::string axis);
    /**
     * @brief Gets the state of a button on the left controller
     *
     * @param button The button to get. Can be "x", "y", "a", "b", "lb", "rb", "back", "start", "lpress", "or" "rpress"
     *
     * @return True if the button is pressed
     */
    bool GetLeftButton(std::string button);
    /**
     * @brief Returns the right joystick
     *
     * @return The right joystick
     */
    Joystick* GetRightStick();
    /**
     * @brief Returns the left joystick
     *
     * @return The left joystick
     */
    Joystick* GetLeftStick();
    /**
     * @brief Returns the left joystick throttle
     *
     * @return The left joystick throttle
     */
    double GetLeftThrottle();
    /**
     * @brief Returns the right joystick throttle
     *
     * @return The right joystick throttle
     */
    double GetRightThrottle();
};
#endif
// vim: ts=2:sw=2:et

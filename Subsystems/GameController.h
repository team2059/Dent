#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "WPILib.h"

/**
 * @brief An xbox or ps3 controller
 */
class GameController{
  private:
    Joystick *stick;        //<! The controller
    std::string type;       //<! The type of controller. Can be "xbox" or "ps3"
    JoystickButton *a,      //<! A key for xbox, x for ps3
                   *b,      //<! B key for xbox, circle for ps3
                   *x,      //<! X key for xbox, square for ps3
                   *y,      //<! Y key for xbox, triangle for ps3
                   *lb,     //<! Left button 
                   *rb,     //<! Right button 
                   *tlb,    //<! Top left Button (ps3 only)  
                   *trb,    //<! Top right button (ps3 only)  
                   *start,  //<! Start button    
                   *back,   //<! Back button   
                   *lPress, //<! Press down on left stick     
                   *rPress, //<! Press down on right stick     
                   *dUp,    //<! D-Pad up  
                   *dDown,  //<! D-Pad down    
                   *dLeft,  //<! D-Pad left    
                   *dRight; //<! D-Pad right     
  public:
    /**
     * @brief Constructs GameController
     *
     * @param port The port of the controller
     * @param controllerType The type of controller. Can be "xbox" or "ps3"
     */
    GameController(int port, std::string controllerType);
    /**
     * @brief Gets the value of a button
     *
     * @param button The button to get
     *
     * @return True only if the button is pressed
     */
    bool GetButton(std::string button);
    /**
     * @brief Gets an axis value
     *
     * @param position Side of the controller. Can be "left" or "right"
     * @param axis The axis to get. Can be "x", "y", or "throttle" for xbox or "x" and "y" for ps3
     *
     * @return The axis value from (-1.0 to 1.0)
     */
    double GetAxis(std::string position, std::string axis);
};
#endif
// vim: ts=2:sw=2:et

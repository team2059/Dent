#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "WPILib.h"

class GameController{
  private:
    Joystick *stick;
    std::string type;
    JoystickButton *a, *b, *x, *y, *lb, *rb, *tlb, *trb, *start, *back, *lPress, *rPress, *dUp, *dDown, *dLeft, *dRight;
  public:
    GameController(int port, std::string controllerType);
    bool GetButton(std::string button);
    double GetAxis(std::string position, std::string axis);
};
#endif
// vim: ts=2:sw=2:et

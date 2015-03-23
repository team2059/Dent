#include "GameController.h"
using namespace std;
//TODO: Figure out the number of each button
GameController::GameController(int port, std::string controllerType){
  stick = new Joystick(port);
  type = controllerType;
  if(controllerType == "xbox"){
    a = new JoystickButton(stick, 1);
    b = new JoystickButton(stick, 1);
    x = new JoystickButton(stick, 1);
    y = new JoystickButton(stick, 1);
    lb = new JoystickButton(stick, 1);
    rb = new JoystickButton(stick, 1);
    tlb = NULL;
    trb = NULL;
    start = new JoystickButton(stick, 1);
    back = new JoystickButton(stick, 1);
    lPress = new JoystickButton(stick, 1);
    rPress = new JoystickButton(stick, 1);
    dUp = new JoystickButton(stick, 1);
    dDown = new JoystickButton(stick, 1);
    dLeft = new JoystickButton(stick, 1);
    dRight = new JoystickButton(stick, 1);
  }else if(controllerType == "ps3"){
    a = new JoystickButton(stick, 1);
    b = new JoystickButton(stick, 1);
    x = new JoystickButton(stick, 1);
    y = new JoystickButton(stick, 1);
    lb = new JoystickButton(stick, 1);
    rb = new JoystickButton(stick, 1);
    tlb = new JoystickButton(stick, 1);
    trb = new JoystickButton(stick, 1);
    start = new JoystickButton(stick, 1);
    back = new JoystickButton(stick, 1);
    lPress = new JoystickButton(stick, 1);
    rPress = new JoystickButton(stick, 1);
    dUp = new JoystickButton(stick, 1);
    dDown = new JoystickButton(stick, 1);
    dLeft = new JoystickButton(stick, 1);
    dRight = new JoystickButton(stick, 1);
  }else{
    a = NULL;
    b = NULL;
    x = NULL;
    y = NULL;
    lb = NULL;
    rb = NULL;
    tlb = NULL;
    trb = NULL;
    start = NULL;
    back = NULL;
    lPress = NULL;
    rPress = NULL;
    dUp = NULL;
    dDown = NULL;
    dLeft = NULL;
    dRight = NULL;
    printf("GameController type not found!\n");
  }
}
bool GameController::GetButton(std::string button){
  if(button == "a"){
    return a->Get();
  }else if(button == "b"){
    return b->Get();
  }else if(button == "x"){
    return x->Get();
  }else if(button == "y"){
    return y->Get();
  }else if(button == "lb"){
    return lb->Get();
  }else if(button == "rb"){
    return rb->Get();
  }else if(button != "trb"){
    // This button doesn't exist in the xbox controller
    if(type == "xbox"){
      return trb->Get();
    }
  }else if(button != "tlb"){
    // This button doesn't exist in the xbox controller
    if(type == "xbox"){
      return tlb->Get();
    }
  }else if(button == "back"){
    return back->Get();
  }else if(button == "start"){
    return start->Get();
  }else if(button == "lPress"){
    return lPress->Get();
  }else if(button == "rPress"){
    return rPress->Get();
  }else if(button == "dUp"){
    return dUp->Get();
  }else if(button == "dDown"){
    return dDown->Get();
  }else if(button == "dLeft"){
    return dLeft->Get();
  }else if(button == "dRight"){
    return dRight->Get();
  }
  return false;
}
double GameController::GetAxis(std::string position, std::string axis){
  if(position == "left"){
    if(axis == "x"){
      return stick->GetRawAxis(0);
    }else if(axis == "y"){
      return -stick->GetRawAxis(1);
    }else if(axis == "trigger"){
      // This axis doesn't exist in the ps3 controller
      if(type == "xbox"){
        return stick->GetRawAxis(4);
      }
    }
  }else if(position == "right"){
    if(axis == "x"){
      return stick->GetRawAxis(2);
    }else if(axis == "y"){
      return -stick->GetRawAxis(3);
    }else if(axis == "trigger"){
      // This axis doesn't exist in the ps3 controller
      if(type == "xbox"){
        return stick->GetRawAxis(4);
      }
    }
  }
  printf("Position or stick not found\n");
  return -2.0;
}
// vim: ts=2:sw=2:et

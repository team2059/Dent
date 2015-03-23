#include "OI.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Elevator/Raise.h"
#include "Commands/Collector/RollIn.h"
#include "Commands/Collector/RollOut.h"
#include "Commands/Collector/RollVar.h"
#include "Commands/BinElevator/BinLower.h"
#include "Commands/BinElevator/BinRaise.h"
#include "Commands/BinElevator/BinCloseArms.h"
#include "Commands/BinElevator/BinOpenArms.h"
#include "Commands/Autonomous/CollectTote.h"
#include "Commands/Autonomous/ReleaseTote.h"
OI::OI(){
  // Joysticks
  leftController=new Joystick(0);
  rightController=new Joystick(1);
  // Collector
  JoystickButton *left10=new JoystickButton(leftController, 10);
  JoystickButton *left12=new JoystickButton(leftController, 12);
  JoystickButton *left9=new JoystickButton(leftController, 9);
  left10->WhileHeld(new RollIn(GetLeftThrottle()));
  left12->WhileHeld(new RollOut(2.0));
  // 0.8 is the multiplier, so they roll at 80% power
  left9->WhileHeld(new RollVar(0.8));
  // Elevator
  raise=new Raise(3.5);
  lower=new Lower(3.0);
  JoystickButton *right9=new JoystickButton(rghtController, 9);
  JoystickButton *right11=new JoystickButton(rghtController, 11);
  right9->WhenPressed(lower);
  right9->CancelWhenPressed(raise);
  right11->WhenPressed(raise);
  right11->CancelWhenPressed(lower);
  // BinElevator
  JoystickButton *right10=new JoystickButton(rghtController, 10);
  JoystickButton *right12=new JoystickButton(rghtController, 12);
  //JoystickButton *right7=new JoystickButton(rghtController, 7);
  //JoystickButton *right8=new JoystickButton(rghtController, 8);
  //right7->WhenPressed(new BinOpenArms());
  //right8->WhenPressed(new BinCloseArms());
  binRaise=new BinRaise(3.0);
  binLower=new BinLower(2.0);
  right10->WhileHeld(binLower);
  right10->CancelWhenPressed(binRaise);
  right12->WhileHeld(binRaise);
  right12->CancelWhenPressed(binLower);
  // Cancel
  JoystickButton *right16=new JoystickButton(rghtController, 16);
  right16->CancelWhenPressed(raise);
  right16->CancelWhenPressed(lower);
}
float OI::GetLeftAxis(std::string stick, std::string axis){
  if(stick=="left"){
    if(axis=="x"){
      return leftController->GetRawAxis(0);
    }else if(axis=="y"){
      return -leftController->GetRawAxis(1);
    }else if(axis=="trigger"){
      //TODO: Figure out what axis this is
      return leftController->GetRawAxis(4);
      return -4;
    }
  }else if(stick=="right"){
    if(axis=="x"){
      return leftController->GetRawAxis(2);
    }else if(axis=="y"){
      return -leftController->GetRawAxis(3);
    }else if(axis=="trigger"){
      //TODO: Figure out what axis this is
      return leftController->GetRawAxis(5);
      return -4;
    }
  }
  //TODO: Fix this placeholder for NULL
  return -5;
}
bool OI::GetLeftButton(std::string button){
    if(button=="a"){
      return leftA->Get();
    }else if(button=="b"){
      return leftB->Get();
    }else if(button=="x"){
      return leftX->Get();
    }else if(button=="y"){
      return leftY->Get();
    }else if(button=="lb"){
      return leftLB->Get();
    }else if(button=="rb"){
      return leftRB->Get();
    }else if(button=="back"){
      return leftBack->Get();
    }else if(button=="start"){
      return leftStart->Get();
    }else if(button=="lpress"){
      return leftLPress->Get();
    }else if(button=="rpress"){
      return leftRPress->Get();
    }
    return false;
}
Joystick* OI::GetRightStick(){
  return rghtController;
}
Joystick* OI::GetLeftStick(){
  return leftController;
}
double OI::GetRightThrottle(){
  return (-rghtController->GetRawAxis(3)+1.0)/2;
}
double OI::GetLeftThrottle(){
  return (-leftController->GetRawAxis(3)+1.0)/2;
}
// vim: ts=2:sw=2:et

#include "OI.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Elevator/Raise.h"
#include "Commands/Collector/RollIn.h"
#include "Commands/Collector/RollOut.h"
#include "Commands/BinElevator/BinLower.h"
#include "Commands/BinElevator/BinRaise.h"
#include "Commands/BinElevator/BinCloseArms.h"
#include "Commands/BinElevator/BinOpenArms.h"
#include "Commands/Autonomous/CollectTote.h"
#include "Commands/Autonomous/ReleaseTote.h"
#include "Commands/Test/CheckRobot.h"
OI::OI(){
  // Joysticks
  leftController=new Joystick(0);
  rightStick=new Joystick(1);
  // Main buttons
  leftA = new JoystickButton(leftController, 1);
  leftB = new JoystickButton(leftController, 2);
  leftX = new JoystickButton(leftController, 3);
  leftY = new JoystickButton(leftController, 4);
  // Left and right uttons
  leftLB = new JoystickButton(leftController, 5);
  leftRB = new JoystickButton(leftController, 6);
  leftBack = new JoystickButton(leftController, 7);
  leftStart = new JoystickButton(leftController, 8);
  // Left, right stick press 
  leftLPress = new JoystickButton(leftController, 9);
  leftRPress = new JoystickButton(leftController, 10);
}
float OI::GetLeftAxis(std::string stick, std::string axis){
  if(stick=="left"){
    if(axis=="x"){
      return leftController->GetX();
    }else if(axis=="y"){
      return -leftController->GetY();
    }else if(axis=="trigger"){
      //TODO: Figure out what axis this is
      return -4;
    }
  }else if(stick=="right"){
    if(axis=="x"){
      return leftController->GetTwist();
    }else if(axis=="y"){
      return -leftController->GetRawAxis(4);
    }else if(axis=="trigger"){
      //TODO: Figure out what axis this is
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
// vim: ts=2:sw=2:et

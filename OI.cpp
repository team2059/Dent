#include "OI.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Elevator/Raise.h"
#include "Commands/Collector/OpenCollector.h"
#include "Commands/Collector/CloseCollector.h"
#include "Commands/Collector/CollectTote.h"
#include "Commands/Collector/ReleaseTote.h"
#include "Commands/Collector/StopCollector.h"
#include "Commands/Collector/StopArm.h"
#include "Commands/Compressor/StartCompressing.h"
#include "Commands/Compressor/StopCompressing.h"

OI::OI() {
  leftStick=new Joystick(0);
  rightStick=new Joystick(1);
  //TODO name these buttons to their functions rather to their number
  JoystickButton *left1=new JoystickButton(leftStick, 1);
  JoystickButton *left2=new JoystickButton(leftStick, 2);
  JoystickButton *left3=new JoystickButton(leftStick, 3);
  JoystickButton *left4=new JoystickButton(leftStick, 4);
  JoystickButton *left5=new JoystickButton(leftStick, 5);
  JoystickButton *left6=new JoystickButton(leftStick, 6);
  JoystickButton *left7=new JoystickButton(leftStick, 7);
  JoystickButton *left8=new JoystickButton(leftStick, 8);
  left1->WhileHeld(new OpenCollector());
  left2->WhileHeld(new CloseCollector());
  left3->WhileHeld(new CollectTote());
  left4->WhileHeld(new ReleaseTote());
  left5->WhileHeld(new StartCompressing());
  left6->WhileHeld(new StopCompressing());
  left7->WhileHeld(new Raise());
  left8->WhileHeld(new Lower());
}
Joystick* OI::GetRightStick(){
  return rightStick;
}
Joystick* OI::GetLeftStick(){
  return leftStick;
}

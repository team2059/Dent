#include "OI.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Elevator/Raise.h"
#include "Commands/Collector/OpenCollector.h"
#include "Commands/Collector/CloseCollector.h"
#include "Commands/Collector/CollectTote.h"
#include "Commands/Collector/ReleaseTote.h"
#include "Commands/Compressor/StartCompressing.h"
#include "Commands/Compressor/StopCompressing.h"

OI::OI() {
  leftStick=new Joystick(0);
  rightStick=new Joystick(1);
  //TODO name these buttons to their functions rather to their number
  JoystickButton *right1=new JoystickButton(rightStick, 1);
  JoystickButton *right2=new JoystickButton(rightStick, 2);
  JoystickButton *right3=new JoystickButton(rightStick, 3);
  JoystickButton *right4=new JoystickButton(rightStick, 4);
  JoystickButton *right5=new JoystickButton(rightStick, 5);
  JoystickButton *right6=new JoystickButton(rightStick, 6);
  JoystickButton *right7=new JoystickButton(rightStick, 7);
  JoystickButton *right8=new JoystickButton(rightStick, 8);
  right1->WhenPressed(new OpenCollector());
  right2->WhenPressed(new CloseCollector());
  right3->WhenPressed(new CollectTote());
  right4->WhenPressed(new ReleaseTote());
  right5->WhenPressed(new StartCompressing());
  right6->WhenPressed(new StopCompressing());
  right7->WhenPressed(new Raise());
  right8->WhenPressed(new Lower());
}
Joystick* OI::GetRightStick(){
  return rightStick;
}
Joystick* OI::GetLeftStick(){
  return leftStick;
}

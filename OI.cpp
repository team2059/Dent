#include "OI.h"
#include "Commands/Lower.h"
#include "Commands/Raise.h"
#include "Commands/Eject.h"
#include "Commands/OpenCollector.h"
#include "Commands/CloseCollector.h"
#include "Commands/CollectTote.h"
#include "Commands/ReleaseTote.h"
#include "Commands/Compressor/StartCompressing.h"
#include "Commands/Compressor/StopCompressing.h"

OI::OI() {
  leftStick=new Joystick(0);
  rightStick=new Joystick(1);
  //TODO name these buttons to their functions rather to their number
  JoystickButton *left10=new JoystickButton(leftStick, 10);
  JoystickButton *left11=new JoystickButton(leftStick, 11);
  JoystickButton *right1=new JoystickButton(rightStick, 1);
  JoystickButton *right2=new JoystickButton(rightStick, 2);
  JoystickButton *right3=new JoystickButton(rightStick, 3);
  JoystickButton *right4=new JoystickButton(rightStick, 4);
  right1->WhenPressed(new OpenCollector());
  right2->WhenPressed(new CloseCollector());
  right3->WhenPressed(new CollectTote());
  right4->WhenPressed(new ReleaseTote());
  left10->WhenPressed(new Eject());
}
Joystick* OI::GetRightStick(){
  return rightStick;
}
Joystick* OI::GetLeftStick(){
  return leftStick;
}

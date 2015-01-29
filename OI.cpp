#include "OI.h"
#include "Commands/Lower.h"
#include "Commands/Raise.h"
#include "Commands/Collect.h"
#include "Commands/Eject.h"
#include "Commands/Compressor/StartCompressing.h"
#include "Commands/Compressor/StopCompressing.h"

OI::OI() {
  leftStick=new Joystick(0);
  rightStick=new Joystick(1);
  JoystickButton *left10=new JoystickButton(leftStick, 10);
  JoystickButton *left11=new JoystickButton(leftStick, 11);
  left10->WhenPressed(new Eject());
  left11->WhenPressed(new Collect());
}
Joystick* OI::GetRightStick(){
  return rightStick;
}
Joystick* OI::GetLeftStick(){
  return leftStick;
}

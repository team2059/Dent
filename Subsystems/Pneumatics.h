#ifndef PNEUMATICS_H
#define PNEUMATICS_H

#include "WPILib.h"
class Pneumatics: public Subsystem{
  private:
    Solenoid *solenoid1, *solenoid2;
  public:
    Pneumatics();
    void InitDefaultCommand();
    void SetOpen(bool);
};
#endif
// vim: ts=2:sw=2:et

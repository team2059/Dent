#ifndef PNUEMATICS_H
#define PNUEMATICS_H

#include "WPILib.h"
class Pnuematics: public Subsystem
{
  private:
    Solenoid *solenoid1, *solenoid2;
  public:
    Pnuematics();
    void InitDefaultCommand();
    void SetOpen(bool);
};
#endif
// vim: ts=2:sw=2:et

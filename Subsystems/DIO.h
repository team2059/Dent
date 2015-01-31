#ifndef DIO_H
#define DIO_H

#include "WPILib.h"
class DIO{
  private:
    DigitalInput *elevatorTop, *elevatorBottom;
  public:
    DIO();
    enum e_dioSig{
      ELEVATORTOP,
      ELEVATORBOTTOM
    };
    void InitDefaultCommand();
    bool Get(e_dioSig);
};
#endif

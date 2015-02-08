#ifndef CALIBRATE_H
#define CALIBRATE_H

#include "Commands/Command.h"
#include "WPILib.h"

class Calibrate: public Command{
  public:
    Calibrate();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
// vim: ts2:sw=2:et

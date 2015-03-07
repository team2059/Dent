#ifndef BINCLOSEARMS_H
#define BINCLOSEARMS_H

#include "Commands/Command.h"
#include "WPILib.h"

class BinCloseArms: public Command{
  public:
    BinCloseArms(double timeout = 0.5);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
// vim: ts=2:sw=2:et

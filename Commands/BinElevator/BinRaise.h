#ifndef BINRAISE_H
#define BINRAISE_H

#include "Commands/Command.h"
#include "WPILib.h"

class BinRaise: public Command{
  public:
    BinRaise();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
// vim: ts=2:sw=2:et

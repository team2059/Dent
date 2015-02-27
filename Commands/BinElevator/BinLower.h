#ifndef BINLOWER_H
#define BINLOWER_H

#include "Commands/Command.h"
#include "WPILib.h"

class BinLower: public Command{
  private:
    float timeout;
  public:
    BinLower(float);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif
// vim: ts=2:sw=2:et

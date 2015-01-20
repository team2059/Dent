#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include "../CommandBase.h"
#include "../DentRobot.h"
#include "Commands/Command.h"
#include "WPILib.h"

class Compress: public Command{
  public:
    Compress();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif

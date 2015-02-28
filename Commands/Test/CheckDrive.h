#ifndef CHECKDRIVE_H
#define CHECKDRIVE_H

#include "Commands/Command.h"
#include "../../CommandBase.h"
#include "../../DentRobot.h"
#include "WPILib.h"

class CheckDrive: public CommandGroup{
  private:
    int motor;
  public:
    CheckDrive(int);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};
#endif

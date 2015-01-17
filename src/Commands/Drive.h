#ifndef DRIVE_H
#define DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"

class Drive: public CommandBase{
public:
	Drive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef EJECT_H
#define EJECT_H

#include "../CommandBase.h"
#include "WPILib.h"

class Eject: public CommandBase{
public:
	Eject();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

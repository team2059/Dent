#ifndef RAISE_H
#define RAISE_H

#include "../CommandBase.h"
#include "WPILib.h"

class Raise: public CommandBase{
public:
	Raise();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

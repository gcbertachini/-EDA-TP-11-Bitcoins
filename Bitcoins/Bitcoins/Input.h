#pragma once
#include "Output.h"
class Input
{
public:
	Input();
	~Input();

private:
	Output * my_out;
	int unlocking_script;
};


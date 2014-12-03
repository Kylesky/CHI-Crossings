#pragma once

#include "Module.hpp"

class ModuleManager{
public:
	void setActiveModule(Module* mod);
	Module* getActiveModule();
};
#pragma once

#include <vector>

#include "Entity.hpp"

enum ModuleType{NONE, CONTINUOUS_SIDE_SCROLLER};

class ModuleHandler{
private:
	float playerProgress;
	std::vector<Entity*> entities;
	ModuleType type;
public:
	ModuleHandler();
	~ModuleHandler();

	void setModuleType(ModuleType mt);
	ModuleType getModuleType();

	float getPlayerProgress();

	void initialize(ModuleType mt = NONE);
	void update(float time);
	void shutdown();
};
#pragma once

#include <vector>

#include "Entity.hpp"
#include "Level.hpp"
#include "GraphicsManager.hpp"
#include "AssetManager.hpp"

enum ModuleType{NONE, CONTINUOUS_SIDE_SCROLLER};

class ModuleHandler{
private:
	static float playerProgress;
	static ModuleType type;
	static Level *level;
	static CharacterEntity *player;
	static std::vector<CharacterEntity*> characters;
	static std::vector<BulletEntity*> bullets;
	static std::vector<ObjectEntity*> objects;

public:
	ModuleHandler();
	~ModuleHandler();

	static void setModuleType(ModuleType mt);
	static ModuleType getModuleType();

	static float getPlayerProgress();

	static void initialize(ModuleType mt = NONE);
	static void update(float time);
	static void shutdown();
	
	static void drawScreen();

	static void initializeContinuousSideScroller();
};


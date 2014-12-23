#pragma once

#include <vector>

#include "Entity.hpp"
#include "Level.hpp"
#include "GraphicsManager.hpp"
#include "AssetManager.hpp"

enum ModuleType{NONE, CONTINUOUS_SIDE_SCROLLER};

class ModuleHandler{
private:
	float playerProgress;
	ModuleType type;
	Level *level;
	CharacterEntity *player;
	std::vector<CharacterEntity*> characters;
	std::vector<BulletEntity*> bullets;
	std::vector<ObjectEntity*> objects;
	AssetManager* assetManager;

public:
	ModuleHandler();
	~ModuleHandler();

	void setModuleType(ModuleType mt);
	ModuleType getModuleType();

	float getPlayerProgress();

	void initialize(AssetManager* am, GraphicsManager* gm, ModuleType mt = NONE);
	void update(float time);
	void shutdown();
	
	void drawScreen(GraphicsManager *gm);
};
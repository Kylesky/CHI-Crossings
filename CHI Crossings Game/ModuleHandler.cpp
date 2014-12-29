#include "ModuleHandler.hpp"

#include <cstdlib>

float ModuleHandler::playerProgress = 0;
ModuleType ModuleHandler::type = NONE;
Level* ModuleHandler::level = NULL;
CharacterEntity* ModuleHandler::player = NULL;
std::vector<CharacterEntity*> ModuleHandler::characters;
std::vector<BulletEntity*> ModuleHandler::bullets;
std::vector<ObjectEntity*> ModuleHandler::objects;

ModuleHandler::ModuleHandler(){
}

ModuleHandler::~ModuleHandler(){
}

void ModuleHandler::setModuleType(ModuleType mt){
	type = mt;
}

ModuleType ModuleHandler::getModuleType(){
	return type;
}

float ModuleHandler::getPlayerProgress(){
	return playerProgress;
}

void ModuleHandler::initialize(ModuleType mt){
	if(mt != NONE) type = mt;
	switch(mt){
	case CONTINUOUS_SIDE_SCROLLER:
		initializeContinuousSideScroller();
		break;
	}
	GraphicsManager::setLevel(level);
	GraphicsManager::loadLevel();
	player = new CharacterEntity(592, 272, 0, 0, 300, 700, 24, 24, 24);
	player->setBehavior(new PlayerBehavior());
	player->setTexture(*(AssetManager::getTexture("Test Character")));
	player->setScale(0.75, 0.75);
}

void ModuleHandler::update(float time){
	//handle networking

	//update everything
	level->moveWorld(0.3f, 0);
	player->update(time, level);
	for(CharacterEntity *e: characters){
		e->update(time, level);
	}
	for(BulletEntity *e: bullets){
		e->update(time, level);
	}
	for(ObjectEntity *e: objects){
		e->update(time, level);
	}
}

void ModuleHandler::shutdown(){
	//delete all entities
	level->shutdown();
	delete level;
	AssetManager::unloadTexture("Test Background");
	delete player;
}

void ModuleHandler::drawScreen(){
	GraphicsManager::drawLevel();
	for(CharacterEntity *e: characters){
		GraphicsManager::drawCharacterEntity(e);
	}
	for(BulletEntity *e: bullets){
		GraphicsManager::drawBulletEntity(e);
	}
	for(ObjectEntity *e: objects){
		GraphicsManager::drawObjectEntity(e);
	}
	GraphicsManager::drawCharacterEntity(player);
}

void ModuleHandler::initializeContinuousSideScroller(){
	level = new Level(10, 200);
	level->setTexture((AssetManager::getTexture("Test Textures")));

	for(int i=0; i<10; i++){
		for(int j=0; j<200; j++){
			if(i == 0 || i == 9 || j == 0 || j == 199){
				level->setCellUV(i, j, 0, 1);
			}else{
				level->setCellPassable(i, j, true);
				level->setCellUV(i, j, 0, 0);
			}
		}
	}

}
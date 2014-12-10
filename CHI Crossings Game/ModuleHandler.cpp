#include "ModuleHandler.hpp"

#include <cstdlib>

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
		int **map = new int*[15];
		for(int i=0; i<15; i++){
			map[i] = new int[200];
			for(int j=0; j<200; j++){
				map[i][j] = rand()%2;
			}
		}
		level = new Level(15, 200, map);
		player = new CharacterEntity();
		player->setBehavior(new PlayerBehavior());
		break;
	}
}

void ModuleHandler::update(float time){
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
	delete player;
}

void ModuleHandler::drawScreen(GraphicsManager *gm){
	gm->drawLevel(level);
	gm->drawEntity(player);
	for(CharacterEntity *e: characters){
		gm->drawEntity(e);
	}
	for(BulletEntity *e: bullets){
		gm->drawEntity(e);
	}
	for(ObjectEntity *e: objects){
		gm->drawEntity(e);
	}
}
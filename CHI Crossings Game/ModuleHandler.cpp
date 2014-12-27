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

void ModuleHandler::initialize(AssetManager* am, GraphicsManager* gm, ModuleType mt){
	if(mt != NONE) type = mt;
	assetManager = am;
	switch(mt){
	case CONTINUOUS_SIDE_SCROLLER:
		int **map = new int*[10];
		for(int i=0; i<10; i++){
			map[i] = new int[200];
			for(int j=0; j<200; j++){
				if(i == 0 || i == 9 || j == 0 || j == 199) map[i][j] = 0;
				else map[i][j] = (rand()%10 != 0);
				if(map[i][j] == 1) map[i][j] |= (1<<8);
			}
		}
		level = new Level(10, 200, map);
		level->setTexture((assetManager->getTexture("Test Background")));
		gm->setLevel(level);
		gm->loadLevel();
		player = new CharacterEntity();
		player->setBehavior(new PlayerBehavior());
		player->setTexture(*(assetManager->getTexture("Test Character")));
		break;
	}
}

void ModuleHandler::update(float time){
	//handle networking

	//update everything
	level->moveWorld(0.3, 0);
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
	assetManager->unloadTexture("Test Background");
	delete player;
}

void ModuleHandler::drawScreen(GraphicsManager *gm){
	gm->drawLevel();
	for(CharacterEntity *e: characters){
		gm->drawEntity(e);
	}
	for(BulletEntity *e: bullets){
		gm->drawEntity(e);
	}
	for(ObjectEntity *e: objects){
		gm->drawEntity(e);
	}
	gm->drawEntity(player);
}
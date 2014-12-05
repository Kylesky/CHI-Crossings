#include "ModuleHandler.hpp"

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

}

void ModuleHandler::update(float time){
}

void ModuleHandler::shutdown(){
	//delete all entities
}
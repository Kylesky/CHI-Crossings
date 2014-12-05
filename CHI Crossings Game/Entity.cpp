#include "Entity.hpp"

Entity::Entity(){
}

Entity::~Entity(){
}

void Entity::setState(EntityState es){
	state = es;
	stateDuration = 0;
}

EntityState Entity::getState(){
	return state;
}

void Entity::addStateTime(float t){
	stateDuration += t;
}

float Entity::getStateTime(){
	return stateDuration;
}
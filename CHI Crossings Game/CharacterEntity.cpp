#include "CharacterEntity.hpp"

CharacterEntity::CharacterEntity(){
}

CharacterEntity::~CharacterEntity(){
	delete behavior;
}

void CharacterEntity::update(float time, Level *level){
	addStateTime(time);
	//process AI/character logic
	behavior->update(this, time, level);
}

void CharacterEntity::setState(CharacterEntityState s){
	state = s;
}

CharacterEntityState CharacterEntity::getState(){
	return state;
}

void CharacterEntity::setOnGround(bool b){
	onGround = b;
}

bool CharacterEntity::isOnGround(){
	return onGround;
}

void CharacterEntity::addStateTime(float t){
	stateDuration += t;
}

float CharacterEntity::getStateTime(){
	return stateDuration;
}

void CharacterEntity::setX(float x){
	setPosition(x, getPosition().y);
}

void CharacterEntity::setY(float y){
	setPosition(getPosition().x, y);
}

void CharacterEntity::setXVel(float xv){
	xvel = xv;
}

void CharacterEntity::setYVel(float yv){
	yvel = yv;
}

void CharacterEntity::setWalkSpeed(float s){
	walkSpeed = s;
}

void CharacterEntity::setJumpSpeed(float s){
	jumpSpeed = s;
}

float CharacterEntity::getX(){
	return getPosition().x;
}

float CharacterEntity::getY(){
	return getPosition().y;
}

float CharacterEntity::getXVel(){
	return xvel;
}

float CharacterEntity::getYVel(){
	return yvel;
}

float CharacterEntity::getWalkSpeed(){
	return walkSpeed;
}

float CharacterEntity::getJumpSpeed(){
	return jumpSpeed;
}

void CharacterEntity::setBehavior(CharacterBehavior *cb){
	behavior = cb;
}
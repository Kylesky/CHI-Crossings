#include "CharacterEntity.hpp"
#include <iostream>

CharacterEntity::CharacterEntity(){
}

CharacterEntity::CharacterEntity(float x, float y, float xv, float yv, float ws, float js, float h, float w, float r){
	setX(x); setY(y);
	setXVel(xv); setYVel(yv);
	setWalkSpeed(ws); setJumpSpeed(js);
	setHeight(h); setWidth(w);
	setCollisionRadius(r);

	setOrigin(32, 32);	
	onGround = onSlower = jumping = false;
	
	stateDuration = 0;
	setState(IDLE_RIGHT);
	behavior = NULL;
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
	if(state != s){
		stateDuration = 0;
		state = s;
	}
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

void CharacterEntity::setOnSlower(bool b){
	onSlower = b;
}

bool CharacterEntity::isOnSlower(){
	return onSlower;
}

void CharacterEntity::setJumping(bool b){
	jumping = b;
}

bool CharacterEntity::isJumping(){
	return jumping;
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

void CharacterEntity::setXY(float x, float y){
	setPosition(x, y);
}

void CharacterEntity::setXVel(float xv){
	xvel = xv;
}

void CharacterEntity::setYVel(float yv){
	yvel = yv;
}

void CharacterEntity::setXYVel(float xv, float yv){
	xvel = xv;
	yvel = yv;
}

void CharacterEntity::setWalkSpeed(float s){
	walkSpeed = s;
}

void CharacterEntity::setJumpSpeed(float s){
	jumpSpeed = s;
}

void CharacterEntity::setHeight(float h){
	height = h;
}

void CharacterEntity::setWidth(float w){
	width = w;
}

void CharacterEntity::setCollisionRadius(float r){
	collisionRadius = r;
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

float CharacterEntity::getHeight(){
	return height;
}

float CharacterEntity::getWidth(){
	return width;
}

float CharacterEntity::getCollisionRadius(){
	return collisionRadius;
}

void CharacterEntity::setBehavior(CharacterBehavior *cb){
	behavior = cb;
}
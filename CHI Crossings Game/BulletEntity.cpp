#include "BulletEntity.hpp"

BulletEntity::BulletEntity(){
}

BulletEntity::~BulletEntity(){
}

void BulletEntity::update(float time, Level *level){
	xvel += xacc*time;
	yvel += yacc*time;
	setPosition(getPosition().x+xvel*time, getPosition().y+yvel*time);
}
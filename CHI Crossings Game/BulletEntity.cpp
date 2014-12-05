#include "BulletEntity.hpp"

BulletEntity::BulletEntity(){
}

BulletEntity::~BulletEntity(){
}

void BulletEntity::update(float time, Level *level){
	xvel += xacc*time;
	yvel += yacc*time;
	xpos += xvel*time;
	ypos += yvel*time;
}
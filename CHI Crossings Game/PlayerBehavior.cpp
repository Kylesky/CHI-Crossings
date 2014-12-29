#include "PlayerBehavior.hpp"
#include <iostream>

void PlayerBehavior::update(CharacterEntity *character, float time, Level *level){
	if(character->isOnGround()){
		if(InputHandler::isKeyPressed(JUMP)){
			character->setJumping(true);
			character->setYVel(-character->getJumpSpeed());
			if(InputHandler::isKeyDown(LEFT)){
				character->setXVel(-character->getWalkSpeed());
				character->setState(JUMP_LEFT);
			}else if(InputHandler::isKeyDown(RIGHT)){
				character->setXVel(character->getWalkSpeed());
				character->setState(JUMP_RIGHT);
			}else{
				character->setXVel(0);
				if(character->getState() == IDLE_LEFT || character->getState() == WALK_LEFT){
					character->setState(JUMP_LEFT);
				}else{
					character->setState(JUMP_RIGHT);
				}
			}
		}else{
			if(InputHandler::isKeyDown(LEFT)){
				character->setXVel(-character->getWalkSpeed());
				character->setState(WALK_LEFT);
			}else if(InputHandler::isKeyDown(RIGHT)){
				character->setXVel(character->getWalkSpeed());
				character->setState(WALK_RIGHT);
			}else{
				if(character->getState() == WALK_LEFT){
					character->setXVel(0);
					character->setState(IDLE_LEFT);
				}else if(character->getState() == WALK_RIGHT){
					character->setXVel(0);
					character->setState(IDLE_RIGHT);
				}
			}
		}
	}else{
		if(character->isJumping() && InputHandler::isKeyUp(JUMP)){
			character->setJumping(false);
		}
		if(InputHandler::isKeyDown(LEFT)){
			character->setXVel(-character->getWalkSpeed());
			character->setState(JUMP_LEFT);
		}else if(InputHandler::isKeyDown(RIGHT)){
			character->setXVel(character->getWalkSpeed());
			character->setState(JUMP_RIGHT);
		}else{
			character->setXVel(0);
		}
	}
	if(character->isJumping()) character->setYVel(character->getYVel()+4);
	else character->setYVel(character->getYVel()+9);
	
	character->setOnGround(false);
	float tx = character->getX() + character->getXVel()*time + signum(character->getXVel()) * character->getCollisionRadius();
	float ty = character->getY() + character->getYVel()*time + signum(character->getYVel()) * character->getCollisionRadius();
	int gridx = (int)(character->getX()/GRID_SIZE);
	int gridy = (int)(character->getY()/GRID_SIZE);

	//check for collision
	
	//check immediate cells (8-direction)
	//check with *level
	//if not colliding, move
	//if colliding stop at farthest possible non-colliding position
	
	bool movx = true;
	bool movy = true;
	bool slowed = false;
	for( int i = gridx-1; i <= gridx+1; ++i ){
		for( int j = gridy-1; j <= gridy+1; ++j ){
			int currgrid = level->getCell( j, i );
			bool passable = level->isCellPassable( j, i );
			bool slower = level->isCellSlower( j, i );

			double ans[2];

			//top
			if( segmentIntersection(ans, character->getX()+character->getWidth()-DBL_EPSILON, character->getY(), character->getX()+character->getWidth()-DBL_EPSILON, ty, i*64+DBL_EPSILON, j*64+DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+DBL_EPSILON) ||
				segmentIntersection(ans, character->getX()-character->getWidth()+DBL_EPSILON, character->getY(), character->getX()-character->getWidth()+DBL_EPSILON, ty, i*64+DBL_EPSILON, j*64+DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+DBL_EPSILON)){
				if(!passable){
					movy = false;
					character->setOnGround(true);
					character->setYVel(0);
				}
			}
			//bottom
			if( segmentIntersection(ans, character->getX()+character->getWidth()-DBL_EPSILON, character->getY(), character->getX()+character->getWidth()-DBL_EPSILON, ty, i*64+DBL_EPSILON, j*64+64-DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+64-DBL_EPSILON) ||
				segmentIntersection(ans, character->getX()-character->getWidth()+DBL_EPSILON, character->getY(), character->getX()-character->getWidth()+DBL_EPSILON, ty, i*64+DBL_EPSILON, j*64+64-DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+64-DBL_EPSILON)){
				if(!passable){
					movy = false;
					character->setYVel(0);
				}
				if(slower){
					slowed = true;
				}
			}
			//left
			if( segmentIntersection(ans, character->getX(), character->getY()+character->getHeight()-DBL_EPSILON, tx, character->getY()+character->getHeight()-DBL_EPSILON, i*64+DBL_EPSILON, j*64+DBL_EPSILON, i*64+DBL_EPSILON, j*64+64-DBL_EPSILON) ||
				segmentIntersection(ans, character->getX(), character->getY()-character->getHeight()+DBL_EPSILON, tx, character->getY()-character->getHeight()+DBL_EPSILON, i*64+DBL_EPSILON, j*64+DBL_EPSILON, i*64+DBL_EPSILON, j*64+64-DBL_EPSILON)){
				if(!passable){
					movx = false;
				}
			}
			//right
			if( segmentIntersection(ans, character->getX(), character->getY()+character->getHeight()-DBL_EPSILON, tx, character->getY()+character->getHeight()-DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+64-DBL_EPSILON) ||
				segmentIntersection(ans, character->getX(), character->getY()-character->getHeight()+DBL_EPSILON, tx, character->getY()-character->getHeight()+DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+64-DBL_EPSILON)){
				if(!passable){
					movx = false;
				}
			}
			
			if( (level->isCellSpikeTop(j, i) && isIntersecting_Circle_Rectangle(character->getX(), character->getY(), character->getCollisionRadius(), i*64+32, j*64+16, 64, 32, 0)) ||
				(level->isCellSpikeBottom(j, i) && isIntersecting_Circle_Rectangle(character->getX(), character->getY(), character->getCollisionRadius(), i*64+32, j*64+48, 64, 32, 0)) ||
				(level->isCellSpikeLeft(j, i) && isIntersecting_Circle_Rectangle(character->getX(), character->getY(), character->getCollisionRadius(), i*64+16, j*64+32, 32, 64, 0)) ||
				(level->isCellSpikeRight(j, i) && isIntersecting_Circle_Rectangle(character->getX(), character->getY(), character->getCollisionRadius(), i*64+48, j*64+32, 32, 64, 0)) ){
					//std::cout << "DEAD " << i << " " << j << std::endl;
			}
		}
	}

	character->setOnSlower(slowed);
	if(movx) character->setX(character->getX() + (1-(slowed/2.0))*character->getXVel()*time);
	if(movy) character->setY(character->getY() + character->getYVel()*time);
}
#include "PlayerBehavior.hpp"
#include <iostream>

void PlayerBehavior::update(CharacterEntity *character, float time, Level *level){
	if(character->isOnGround()){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			character->setYVel(-character->getJumpSpeed());
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				character->setXVel(-character->getWalkSpeed());
				character->setState(JUMP_LEFT);
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
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
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				character->setXVel(-character->getWalkSpeed());
				character->setState(WALK_LEFT);
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
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
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			character->setXVel(-character->getWalkSpeed());
			character->setState(JUMP_LEFT);
		}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			character->setXVel(character->getWalkSpeed());
			character->setState(JUMP_RIGHT);
		}else{
			character->setXVel(0);
		}
		character->setYVel(character->getYVel()+5);
	}
	
	character->setOnGround(false);
	float newx = character->getX() + character->getXVel()*time;
	float newy = character->getY() + character->getYVel()*time;
	float tx = newx + signum(character->getXVel()) * character->getCollisionRadius();
	float ty = newy + signum(character->getYVel()) * character->getCollisionRadius();
	int gridx = (int)(character->getX()/GRID_SIZE);
	int gridy = (int)(character->getY()/GRID_SIZE);

	//check for collision
	
	//check immediate cells (8-direction)
	//check with *level
	//if not colliding, move
	//if colliding stop at farthest possible non-colliding position
	
	bool movx = true;
	bool movy = true;
	for( int i = gridx-1; i <= gridx+1; ++i ){
		for( int j = gridy-1; j <= gridy+1; ++j ){
			int currgrid = level->getCell( j, i );
			bool passable = (currgrid & (1<<8)) != 0;
			if(!passable){
				double ans[2];

				//top
				if( segmentIntersection(ans, character->getX()+character->getWidth()-DBL_EPSILON, character->getY(), character->getX()+character->getWidth()-DBL_EPSILON, ty, i*64+DBL_EPSILON, j*64+DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+DBL_EPSILON) ||
					segmentIntersection(ans, character->getX()-character->getWidth()+DBL_EPSILON, character->getY(), character->getX()-character->getWidth()+DBL_EPSILON, ty, i*64+DBL_EPSILON, j*64+DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+DBL_EPSILON)){
					movy = false;
					character->setOnGround(true);
					character->setYVel(0);
					//std::cout << "top " << i << " " << j << std::endl;
				}
				//bottom
				if( segmentIntersection(ans, character->getX()+character->getWidth()-DBL_EPSILON, character->getY(), character->getX()+character->getWidth()-DBL_EPSILON, ty, i*64+DBL_EPSILON, j*64+64-DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+64-DBL_EPSILON) ||
					segmentIntersection(ans, character->getX()-character->getWidth()+DBL_EPSILON, character->getY(), character->getX()-character->getWidth()+DBL_EPSILON, ty, i*64+DBL_EPSILON, j*64+64-DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+64-DBL_EPSILON)){
					movy = false;
					character->setYVel(0);
					//std::cout << "bottom " << i << " " << j << std::endl;
				}
				//left
				if( segmentIntersection(ans, character->getX(), character->getY()+character->getHeight()-DBL_EPSILON, tx, character->getY()+character->getHeight()-DBL_EPSILON, i*64+DBL_EPSILON, j*64+DBL_EPSILON, i*64+DBL_EPSILON, j*64+64-DBL_EPSILON) ||
					segmentIntersection(ans, character->getX(), character->getY()-character->getHeight()+DBL_EPSILON, tx, character->getY()-character->getHeight()+DBL_EPSILON, i*64+DBL_EPSILON, j*64+DBL_EPSILON, i*64+DBL_EPSILON, j*64+64-DBL_EPSILON)){
					movx = false;
					//std::cout << "left " << i << " " << j << std::endl;
				}
				//right
				if( segmentIntersection(ans, character->getX(), character->getY()+character->getHeight()-DBL_EPSILON, tx, character->getY()+character->getHeight()-DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+64-DBL_EPSILON) ||
					segmentIntersection(ans, character->getX(), character->getY()-character->getHeight()+DBL_EPSILON, tx, character->getY()-character->getHeight()+DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+DBL_EPSILON, i*64+64-DBL_EPSILON, j*64+64-DBL_EPSILON)){
					movx = false;
					//std::cout << "right " << i << " " << j << std::endl;
				}
			}
		}
	}

	if(movx) character->setX(newx);
	if(movy) character->setY(newy);
}
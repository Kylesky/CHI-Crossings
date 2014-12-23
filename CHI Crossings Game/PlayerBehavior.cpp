#include "PlayerBehavior.hpp"
#include <iostream>

void PlayerBehavior::update(CharacterEntity *character, float time, Level *level){
	if(character->isOnGround()){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			character->setOnGround(false);
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
		}
		character->setYVel(character->getYVel()+20);
	}
	
	float newx = character->getX() + character->getXVel()*time;
	float newy = character->getY() + character->getYVel()*time;
	int gridx = character->getX()/GRID_SIZE;
	int gridy = character->getY()/GRID_SIZE;

	//check for collision
	
	//check immediate cells (8-direction)
	//check with *level
	//if not colliding, move
	//if colliding stop at farthest possible non-colliding cell 

	for( int i = gridx-1; i <= gridx+1; ++i ){
		for( int j = gridy-1; j <= gridy+1; ++j ){
			int currgrid = level->getCell( i, j );
			bool passable = currgrid & (1<<8);
			if(!passable){
				double ans[2];
				float ang = atan2(character->getYVel()*time, character->getXVel()*time);
				
				double tx = character->getX() - cos(ang)*CHARRAD;
				double ty = character->getY() - sin(ang)*CHARRAD;
				double tx2 = newx + cos(ang)*CHARRAD;
				double ty2 = newy + sin(ang)*CHARRAD;
				if(i == gridx+1 && j == gridy){
					std::cout << tx << " " << ty << " " << tx2 << " " << ty2 << std::endl;
					std::cout << i*64 << " " << j*64 << " " << i*64 << " " << j*64+64 << std::endl;
				}
				//left
				if( segmentIntersection(ans, tx, ty, tx2, ty2, i*64, j*64, i*64, j*64+64)){
					newx = ans[0] - cos(ang)*CHARRAD;
					newy = ans[1] - sin(ang)*CHARRAD;
					std::cout << "fahjsdlkhfakjdshflkajsdhfjklasdhfkaljsdhflakjsdhflkajsdhklwah" << std::endl;
				}
				//right
				if( segmentIntersection(ans, tx, ty, tx2, ty2, i*64+64, j*64, i*64+64, j*64+64)){
					newx = ans[0] - cos(ang)*CHARRAD;
					newy = ans[1] - sin(ang)*CHARRAD;
				}
				//top
				if( segmentIntersection(ans, tx, ty, tx2, ty2, i*64, j*64, i*64+64, j*64)){
					newx = ans[0] - cos(ang)*CHARRAD;
					newy = ans[1] - sin(ang)*CHARRAD;
				}
				//bottom
				if( segmentIntersection(ans, tx, ty, tx2, ty2, i*64, j*64+64, i*64+64, j*64+64)){
					newx = ans[0] - cos(ang)*CHARRAD;
					newy = ans[1] - sin(ang)*CHARRAD;
				}
			}
		}
	}

	character->setX(newx);
	character->setY(newy);
}
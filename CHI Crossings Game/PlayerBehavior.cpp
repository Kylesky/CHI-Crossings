#include "PlayerBehavior.hpp"

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
				character->setState(WALK_LEFT);
			}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				character->setState(WALK_RIGHT);
			}else{
				if(character->getState() == WALK_LEFT){
					character->setState(IDLE_LEFT);
				}else if(character->getState() == WALK_RIGHT){
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
	}
	
	float newx = character->getX() + character->getXVel()*time;
	float newy = character->getY() + character->getYVel()*time;
	int gridx = character->getX()/GRID_SIZE;
	int gridy = character->getY()/GRID_SIZE;

	//check for collision
}
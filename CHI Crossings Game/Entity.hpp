#pragma once

#include <SFML/Graphics.hpp>

enum EntityState{IDLE_LEFT, IDLE_RIGHT, WALK_LEFT, WALK_RIGHT, JUMP_LEFT, JUMP_RIGHT, ATTACK_LEFT, ATTACK_RIGHT};

class Entity : sf::Sprite{
private:
	EntityState state;
	float stateDuration;
public:
	Entity();
	~Entity();

	void setState(EntityState es);
	EntityState getState();

	void addStateTime(float t);
	float getStateTime();
};

#include "BulletEntity.hpp"
#include "CharacterEntity.hpp"
#include "ObjectEntity.hpp"
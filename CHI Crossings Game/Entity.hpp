#pragma once

#include "Level.hpp"
#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite{
private:
public:
	Entity();
	~Entity();

	virtual void update(float time, Level *level) = 0;
};

#include "BulletEntity.hpp"
#include "CharacterEntity.hpp"
#include "ObjectEntity.hpp"
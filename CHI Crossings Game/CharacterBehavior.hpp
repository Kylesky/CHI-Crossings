#pragma once

class CharacterEntity;
class Level;

class CharacterBehavior{
public:
	CharacterBehavior();
	~CharacterBehavior();

	virtual void update(CharacterEntity *character, float time, Level *level) = 0;
};

#include "CharacterEntity.hpp"
#include "PlayerBehavior.hpp"
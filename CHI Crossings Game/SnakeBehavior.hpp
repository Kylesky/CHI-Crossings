#pragma once

#include "CharacterBehavior.hpp"

class SnakeBehavior : public CharacterBehavior{
private:
	bool movingRight;
public:
	SnakeBehavior();
	~SnakeBehavior();

	void update(CharacterEntity *character, float time, Level *level);
};
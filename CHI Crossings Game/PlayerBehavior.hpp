#pragma once

#include "CharacterBehavior.hpp"
#include <SFML/Window.hpp>

class PlayerBehavior : public CharacterBehavior{
public:
	void update(CharacterEntity *character, float time, Level *level);
};
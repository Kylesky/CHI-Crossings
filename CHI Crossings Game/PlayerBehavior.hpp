#pragma once

#include "CharacterBehavior.hpp"
#include "InputHandler.hpp"
#include "GeomLib.hpp"
#include <SFML/Window.hpp>

class PlayerBehavior : public CharacterBehavior{
public:
	void update(CharacterEntity *character, float time, Level *level);
};
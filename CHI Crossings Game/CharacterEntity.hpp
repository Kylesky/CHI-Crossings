#pragma once

#include "Entity.hpp"

class CharacterEntity : Entity{
private:
	float health;
	float xpos, ypos;
	float xvel, yvel;
	float walkSpeed, jumpSpeed;

public:
	CharacterEntity();
	~CharacterEntity();
};
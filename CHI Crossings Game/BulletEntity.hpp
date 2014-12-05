#pragma once

#include "Entity.hpp"

class BulletEntity : Entity{
private:
	float xpos, ypos;
	float xvel, yvel;
	float xacc, yacc;
	float damage;
	bool penetrating;
public:
	BulletEntity();
	~BulletEntity();
};
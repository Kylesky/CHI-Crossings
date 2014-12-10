#pragma once

#include "Entity.hpp"

class BulletEntity : public Entity{
private:
	float xvel, yvel;
	float xacc, yacc;
	float damage;
	bool penetrating;
public:
	BulletEntity();
	~BulletEntity();
	void update(float time, Level *level);
};
#pragma once

#include "Entity.hpp"

class ObjectEntity : public Entity{
private:
	float xpos, ypos;
	bool colliding;
public:
	ObjectEntity();
	~ObjectEntity();
	void update(float time, Level *level);
};
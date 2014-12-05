#pragma once

#include "Entity.hpp"

class ObjectEntity : Entity{
private:
	float xpos, ypos;
	bool colliding;
public:
	ObjectEntity();
	~ObjectEntity();
};
#pragma once

#include "Entity.hpp"

class ObjectEntity : public Entity{
private:
	bool colliding;
public:
	ObjectEntity();
	~ObjectEntity();
	void update(float time, Level *level);
};
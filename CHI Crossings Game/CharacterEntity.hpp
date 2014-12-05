#pragma once

#include "Entity.hpp"
#include "CharacterBehavior.hpp"

enum CharacterEntityState{IDLE_LEFT, IDLE_RIGHT, WALK_LEFT, WALK_RIGHT, JUMP_LEFT, JUMP_RIGHT, ATTACK_LEFT, ATTACK_RIGHT};

class CharacterEntity : public Entity{
private:
	float health;
	float xpos, ypos;
	float xvel, yvel;
	float walkSpeed, jumpSpeed;
	CharacterBehavior *behavior;
	CharacterEntityState state;
	float stateDuration;
	bool onGround;
public:
	CharacterEntity();
	~CharacterEntity();

	void setState(CharacterEntityState s);
	CharacterEntityState getState();

	void addStateTime(float t);
	float getStateTime();

	void setOnGround(bool b);
	bool isOnGround();
	void setX(float x);
	void setY(float y);
	void setXVel(float xv);
	void setYVel(float yv);
	void setWalkSpeed(float s);
	void setJumpSpeed(float s);
	float getX();
	float getY();
	float getXVel();
	float getYVel();
	float getWalkSpeed();
	float getJumpSpeed();

	void setBehavior(CharacterBehavior *cb);

	void update(float time, Level *level);
};
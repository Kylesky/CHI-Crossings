#pragma once

#include "Entity.hpp"
#include "CharacterBehavior.hpp"

enum CharacterEntityState{IDLE_LEFT, IDLE_RIGHT, WALK_LEFT, WALK_RIGHT, JUMP_LEFT, JUMP_RIGHT, ATTACK_LEFT, ATTACK_RIGHT};

class CharacterEntity : public Entity{
private:
	float health;
	float xvel, yvel;
	float walkSpeed, jumpSpeed;
	float height, width;
	float collisionRadius;
	CharacterBehavior *behavior;
	CharacterEntityState state;
	float stateDuration;
	bool onGround, onSlower, jumping;
public:
	CharacterEntity();
	CharacterEntity(float x, float y, float xv, float yv, float ws, float js, float h, float w, float r);
	~CharacterEntity();

	void setState(CharacterEntityState s);
	CharacterEntityState getState();

	void addStateTime(float t);
	float getStateTime();

	void setOnGround(bool b);
	bool isOnGround();
	void setOnSlower(bool b);
	bool isOnSlower();
	void setJumping(bool b);
	bool isJumping();
	void setX(float x);
	void setY(float y);
	void setXY(float x, float y);
	void setXVel(float xv);
	void setYVel(float yv);
	void setXYVel(float xv, float yv);
	void setWalkSpeed(float s);
	void setJumpSpeed(float s);
	void setHeight(float h);
	void setWidth(float w);
	void setCollisionRadius(float r);
	float getX();
	float getY();
	float getXVel();
	float getYVel();
	float getWalkSpeed();
	float getJumpSpeed();
	float getHeight();
	float getWidth();
	float getCollisionRadius();

	void setBehavior(CharacterBehavior *cb);

	void update(float time, Level *level);
};
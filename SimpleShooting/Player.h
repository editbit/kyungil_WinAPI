#pragma once
#include "Shooter.h"

#define SKILL_MAX 2

class Player : public Shooter
{
	Skill* skill[SKILL_MAX];
	int bulletShootCount;

public:
	Player();
	~Player();

	Bullet* getBulletPtr() { return _bullet; }
	Skill& getSkill(int index) { return *skill[index]; }
	void userSKill(int index, float angle);
	void moveSKill();
	void drawSkill(HDC hdc);
	void collideSkill(MovableObject& mo);


	void setSKill(int index, Skill* s);

	virtual void shoot(float angle);


};


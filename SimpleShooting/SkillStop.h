#pragma once
#include "Skill.h"
class SkillStop :
	public Skill
{
private:
	int _shootCount;
	Bullet* _bullet;
	const int BULLET_MAX;

public:
	SkillStop(Bullet* bullet, int max);
	~SkillStop();


	virtual void useSkill(float x, float y, float angle);
	virtual void skillCollide(MovableObject& mo) {}
	virtual void moveSkill() {}
	virtual void drawSkill(HDC hdc) {}

	virtual void setIsActive(bool isActive) {}
	virtual bool getIsActive() { return true; }
};


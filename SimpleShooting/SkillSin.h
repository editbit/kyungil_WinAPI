#pragma once
#include "Shooter.h"
class SkillSin :
	public Shooter, public Skill
{
private:
	int skillCount;

public:
	SkillSin();
	~SkillSin();

	virtual void useSkill(float x, float y, float angle);
	virtual void skillCollide(MovableObject& mo);
	virtual void moveSkill();
	virtual void drawSkill(HDC hdc);
	virtual void setIsActive(bool isActive);
	virtual bool getIsActive();
};


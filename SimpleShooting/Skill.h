#pragma once
class Skill
{
protected:
	int _shootCount;
	bool isFired;

public:
	Skill();
	virtual ~Skill();

	virtual void useSkill(float x, float y, float angle) = 0;
	virtual void skillCollide(MovableObject& mo) = 0;
	virtual void moveSkill() = 0;
	virtual void drawSkill(HDC hdc) = 0;
	virtual void setIsFired(bool isActive) { isFired = isActive; };
	virtual bool getIsFired() { return isFired; };
};
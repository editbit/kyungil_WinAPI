#pragma once
class SkillSprinkler : public Shooter,
						public Skill
{
	float _angle;

public:
	SkillSprinkler();
	virtual ~SkillSprinkler();

	virtual void draw(HDC hdc);

	void setAngle(float a) { _angle = a; }
	float getAngle() { return _angle; }

	virtual void move();
	virtual void shoot(float angle);

	virtual void useSkill(float x, float y, float angle);
	virtual void skillCollide(MovableObject& mo);
	virtual void moveSkill();
	virtual void drawSkill(HDC hdc);

};


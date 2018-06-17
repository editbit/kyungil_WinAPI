#include "stdafx.h"
#include "SkillSin.h"


SkillSin::SkillSin() : Shooter(20)
{
	_bullet = new BulletSin[BULLET_MAX];
	skillCount = 0;
	
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		_bullet[i].setIsActive(false);
	}
}


SkillSin::~SkillSin()
{
	delete[] _bullet;
}

void SkillSin::useSkill(float x, float y, float angle)
{

	skillCount = (skillCount + 1) % 5;

	if (skillCount != 0)
		return;

	for (int i = 0; i < BULLET_MAX; ++i)
	{
		if (!_bullet[i].getIsActive())
		{
			_bullet[i].setX(x);
			_bullet[i].setY(y);
			_bullet[i].setDir(angle);
			_bullet[i].setSpeed(5.0f);
			_bullet[i].setIsActive(true);
			break;
		}
	}
}

void SkillSin::skillCollide(MovableObject & mo)
{
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		if (_bullet[i].getIsActive() && _bullet[i].collide(mo))
		{
			_bullet[i].setIsActive(false);
			mo.hitBullet();
		}
	}
}

void SkillSin::moveSkill()
{
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		if (_bullet[i].getIsActive())
		{
			_bullet[i].move();
		}
	}
}

void SkillSin::drawSkill(HDC hdc)
{
	for (int i = 0; i < 20; ++i)
	{
		if (_bullet[i].getIsActive())
		{
			_bullet[i].draw(hdc);
		}
	}
}

void SkillSin::setIsActive(bool isActive)
{
	//Shooter::setIsActive(isActive);
}

bool SkillSin::getIsActive()
{
	return true;
}



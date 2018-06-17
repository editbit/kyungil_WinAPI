#include "stdafx.h"
#include "SkillCircle.h"


SkillCircle::SkillCircle(Bullet* bullet, int max = 10) : BULLET_MAX(max)
{
	_bullet = bullet;
}


SkillCircle::~SkillCircle()
{
}



void SkillCircle::useSkill(float x, float y, float angle)
{
	float a = 0;
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		if (!_bullet[i].getIsActive())
		{
			_bullet[i].setX(x);
			_bullet[i].setX(x + 100 + cos( a ) * 50);
			_bullet[i].setY(y + sin( a ) * 50);
			_bullet[i].setSpeed(1.0f);
			_bullet[i].setDir(angle);
			_bullet[i].setIsActive(true);

			a = a + 3.141592f / 5;
		}
	}
}


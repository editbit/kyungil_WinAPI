#include "stdafx.h"
#include "SkillStop.h"


SkillStop::SkillStop(Bullet* bullet, int max = 10) : BULLET_MAX(max)
{
	_bullet = bullet;
}


SkillStop::~SkillStop()
{
}

void SkillStop::useSkill(float x, float y, float angle)
{
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		if (_bullet[i].getIsActive())
		{
			float d = 1;
			if (angle == 180.0f)
				d = -1;
			else if (angle == 0)
				d = 1;
			_bullet[i].setX(_bullet[i].getX() - d * _bullet[i].getSpeed());
			
		}
	}
}

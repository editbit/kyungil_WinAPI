#include "stdafx.h"
#include "SkillSprinkler.h"

SkillSprinkler::SkillSprinkler() : Shooter(20)
{
	_bullet = new Bullet[BULLET_MAX];
	_bulletCount = 0;
	_speed = 3.0f;
	_size = 10;
	_isActive = false;
	_shootCount = 0;
}

SkillSprinkler::~SkillSprinkler()
{
	delete[] _bullet;
}

void SkillSprinkler::draw(HDC hdc)
{
	if (getIsFired())
	{
		SetDCBrushColor(hdc, RGB(255, 0, 0));
		SelectObject(hdc, GetStockObject(DC_BRUSH));

		Ellipse(hdc, _x - _size / 2, _y - _size / 2, _x + _size / 2, _y + _size / 2);

		SetDCBrushColor(hdc, RGB(255, 255, 255));
		SelectObject(hdc, GetStockObject(DC_BRUSH));
	}
}

void SkillSprinkler::move()
{
	Shooter::move();

	if (_x < 0 || _x >= WINSIZEX)
		setIsFired(false);

	if (getIsFired() && (_shootCount++) % 5 == 0)
	{
		shoot(_angle);
		_angle = (_angle + 30.0f);
		if (_angle >= 360)
			_angle -= 360;
	}

	bulletMove();
}

void SkillSprinkler::shoot(float angle)
{
	Shooter::shoot(angle);
}


void SkillSprinkler::useSkill(float x, float y, float angle)
{
	setX(x);
	setY(y);
	setDir(angle);
	setAngle(angle);
	setSize(10);
	setSpeed(3.0f);
	setIsFired(true);
	setIsActive(true);
}

void SkillSprinkler::skillCollide(MovableObject& mo)
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


void SkillSprinkler::moveSkill()
{
	move();
}

void SkillSprinkler::drawSkill(HDC hdc)
{
	if (getIsFired())
	{
		draw(hdc);
	}
	bulletDraw(hdc);
}

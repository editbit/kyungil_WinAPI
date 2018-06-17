#include "stdafx.h"
#include "BulletSin.h"


BulletSin::BulletSin()
{
}


BulletSin::~BulletSin()
{
}

void BulletSin::move()
{
	if (_isActive)
	{
		_x = _x + _dirX * _speed;
		_y = _y + _dirY * _speed + sin(_x / 25)*5;

		if (_x < 0 || _x >= WINSIZEX)
			_isActive = false;
		if (_y < 0 || _y >= WINSIZEY)
			_isActive = false;
	}

}
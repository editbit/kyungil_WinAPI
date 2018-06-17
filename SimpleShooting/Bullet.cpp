#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
	_size = 25;
}


Bullet::~Bullet()
{

}

void Bullet::draw(HDC hdc)
{
	Ellipse(hdc, _x - _size / 2, _y - _size / 2, _x + _size / 2, _y + _size / 2);
}

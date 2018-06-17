#include "stdafx.h"
#include "MovableObject.h"


MovableObject::MovableObject()
{
	_isActive = false;
	_speed = 1.0f;
}


MovableObject::~MovableObject()
{
}

void MovableObject::setDir(float angle)
{
	_dirX = cos(3.141592f / 180 * angle);
	_dirY = sin(3.141592f / 180 * angle);
}

void MovableObject::setDir(float x, float y)
{
	float distance = sqrt((x - _x)*(x - _x) + (y - _y)*(y - _y));
	_dirX = (x - _x) / (distance / _speed);
	_dirY = (_y - y) / (distance / _speed);
}

void MovableObject::move()
{
	if (_isActive)
	{
		_x = _x + _dirX * _speed;
		_y = _y + _dirY * _speed;

		if (_x < 0 || _x >= WINSIZEX)
			_isActive = false;
		if (_y < 0 || _y >= WINSIZEY)
			_isActive = false;
	}

}

bool MovableObject::collide(MovableObject& r)
{
	float distance = sqrt((_x - r.getX())*(_x - r.getX()) + (_y - r.getY())*(_y - r.getY()));
	if (distance < _size / 2 + r.getSize() / 2)
		return true;

	return false;
}

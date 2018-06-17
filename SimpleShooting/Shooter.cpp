#include "stdafx.h"
#include "Shooter.h"


Shooter::Shooter() : BULLET_MAX(10)
{

}

Shooter::Shooter(int max) : BULLET_MAX(max)
{
}

Shooter::~Shooter()
{
}

void Shooter::move(MOVE_STATE moveState)
{
	if (!_isActive)
		return;
	if (moveState == LEFT)
		_x = _x - _speed;
	else if (moveState == RIGHT)
		_x = _x + _speed;
	else if (moveState == UP)
		_y = _y - _speed;
	else if (moveState == DOWN)
		_y = _y + _speed;
	
	if (_x < 0)
		_x = 0;
	if (_x >= WINSIZEX)
		_x = WINSIZEX - 1;
	if (_y < 0)
		_y = 0;
	if (_y >= WINSIZEY)
		_y = WINSIZEY - 1;
}

void Shooter::draw(HDC hdc)
{
	SetDCBrushColor(hdc, RGB(_hp.r, _hp.g, _hp.b));
	SelectObject(hdc, GetStockObject(DC_BRUSH));
	
	//HBRUSH brush = CreateSolidBrush(RGB(_hp.r, 255, _hp.b));
	Rectangle(hdc, _hp.rc);
	//DeleteObject(brush);

	SetDCBrushColor(hdc, RGB(255, 255, 255));
	SelectObject(hdc, GetStockObject(DC_BRUSH));
	if (!_isActive)
		return;
	_rc[0].left = _x - _size / 2;
	_rc[0].right = _x + _size / 2;
	_rc[0].top = _y - _size / 2;
	_rc[0].bottom = _y + _size / 2;
	Rectangle(hdc, _rc[0]);
}

void Shooter::hitBullet()
{
	if (team == 0)
	{
		_hp.rc.right -= 10;
		if (_hp.rc.right <= _hp.rc.left)
		{
			_hp.rc.right = _hp.rc.left;
			_isActive = false;
		}
	}
	else if (team == 1)
	{
		_hp.rc.left += 10;
		if (_hp.rc.left >= _hp.rc.right)
		{
			_hp.rc.left = _hp.rc.right;
			_isActive = false;
		}
	}

	if (_hp.rc.right - _hp.rc.left < 100)
	{
		_hp.r = 0xEB;
		_hp.g = 0x00;
		_hp.b = 0x00;
	}
	else if (_hp.rc.right - _hp.rc.left < 200)
	{
		_hp.r = 0xFF;
		_hp.g = 0xD7;
		_hp.b = 0x32;
	}
}

int Shooter::getTeam()
{
	return team;
}

void Shooter::setTeam(int a)
{
	team = a;
	if (a == 0)
	{
		_hp.rc = { 10, 10, 300, 25 };
		_hp.r = 0;
		_hp.b = 0;
		_hp.g = 255;
	}
	else if (a == 1)
	{
		_hp.rc = { WINSIZEX - 310, 10, WINSIZEX - 10, 25 };
		_hp.r = 0;
		_hp.b = 0;
		_hp.g = 255;
	}
}

void Shooter::bulletMove()
{
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		if(_bullet[i].getIsActive())
			_bullet[i].move();
	}
}

void Shooter::bulletDraw(HDC hdc)
{
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		if (_bullet[i].getIsActive())
			_bullet[i].draw(hdc );
	}
}

void Shooter::shoot(float angle)
{
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		if (!_bullet[_bulletCount].getIsActive())
		{
			_bullet[_bulletCount].setX(_x);
			_bullet[_bulletCount].setY(_y);
			_bullet[_bulletCount].setDir(angle);
			_bullet[_bulletCount].setSpeed(5.0f);
			_bullet[_bulletCount].setIsActive(true);
			break;
		}
		_bulletCount = (_bulletCount + 1) % BULLET_MAX;
	}
}

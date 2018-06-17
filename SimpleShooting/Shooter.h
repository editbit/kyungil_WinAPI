#pragma once
#include "MovableObject.h"

enum MOVE_STATE{
	LEFT = 1, RIGHT = 2, UP = 4, DOWN = 8, STOP = 0
};
struct HP
{
	RECT rc;
	int hp;
	int r, g, b;
};

class Shooter : public MovableObject
{
protected:
	Bullet* _bullet;
	int _bulletCount;
	const int BULLET_MAX;
	int team;

	RECT _rc[2];

	HP _hp;

public:
	Shooter();
	Shooter(int max);
	virtual ~Shooter();

	virtual void move() { MovableObject::move(); }
	virtual void move(MOVE_STATE);
	virtual void draw(HDC hdc);

	int getMaxBullet() { return BULLET_MAX; }
	virtual void hitBullet();

	Bullet& getBullet(int index) { return _bullet[index];  }

	int getTeam();
	void setTeam(int a);
	
	void bulletMove();
	void bulletDraw(HDC hdc);

	virtual void shoot(float angle);

	int getBulletMax() { return BULLET_MAX; }
};


#pragma once
#include "MovableObject.h"
class Bullet : public MovableObject
{
private:

public:
	Bullet();
	~Bullet();

	virtual void draw(HDC hdc);
};


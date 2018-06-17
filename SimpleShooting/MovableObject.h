#pragma once
class MovableObject
{
protected:
	float _x, _y, _speed, _dirX, _dirY;
	bool _isActive;
	int _size;

public:
	MovableObject();
	virtual ~MovableObject();

	int getSize() { return _size; }
	void setSize(int size) { _size = size; }

	float getX() {return _x;}
	void setX(float x) { _x = x; }

	float getY() { return _y; }
	void setY(float y) { _y = y; }

	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }

	float getDirX() { return _dirX; }
	void setDirX(float dirX) { _dirX = dirX; }

	float getDirY() { return _dirY; }
	void setDirY(float dirY) { _dirY = dirY; }

	bool getIsActive() { return _isActive; }
	void setIsActive(bool isActive) { _isActive = isActive; }

	void setDir(float angle);
	void setDir(float x, float y);

	virtual void move();

	virtual void draw(HDC hdc) {}

	virtual bool collide(MovableObject& r);

	virtual void hitBullet() {}	// Skill¿ë
};


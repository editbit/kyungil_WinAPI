#include "stdafx.h"
#include "Player.h"


Player::Player()
{

	_bullet = new Bullet[BULLET_MAX];
	_bulletCount = 0;
	_speed = 5.0f;
	_size = 50;
	
	bulletShootCount = 0;

	_isActive = true;

}


Player::~Player()
{
	delete[] _bullet;

	if (skill[0] != NULL)
		delete skill[0];
	if (skill[1] != NULL)
		delete skill[1];
}

void Player::setSKill(int index, Skill* s)
{ 
	skill[index] = s;
	skill[index]->setIsFired(false);
}

void Player::userSKill(int index, float angle)
{ 
	if(!skill[index]->getIsFired())
		skill[index]->useSkill(_x, _y, angle);
}
void Player::moveSKill()
{
	skill[0]->moveSkill();
	skill[1]->moveSkill();
}
void Player::drawSkill(HDC hdc)
{
	skill[0]->drawSkill(hdc);
	skill[1]->drawSkill(hdc);
}
void Player::collideSkill(MovableObject & mo)
{
	skill[0]->skillCollide(mo);
	skill[1]->skillCollide(mo);
}

void Player::shoot(float angle)
{
	if (bulletShootCount == 0)
		Shooter::shoot(angle);
	bulletShootCount = (bulletShootCount + 1) % 10;
}
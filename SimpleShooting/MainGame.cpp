#include "stdafx.h"
#include "MainGame.h"

//=============================================================
//	## �ʱ�ȭ ## init(void)
//=============================================================
HRESULT MainGame::init(void)
{
	GameNode::init();
	// �̰����� �ʱ�ȭ�� �Ѵ�.

	user = new Player[2];
	user[0].setTeam(0);
	user[1].setTeam(1);

	user[0].setSize(50);
	user[1].setSize(50);

	user[0].setX(25);
	user[0].setY(WINSIZEY / 2);
	user[1].setX(WINSIZEX - 25);
	user[1].setY(WINSIZEY / 2);

	user[0].setSKill(0, new SkillSin());
	user[0].setSKill(1, new SkillCircle(user[0].getBulletPtr(), 10));

	user[1].setSKill(0, new SkillSprinkler());
	user[1].setSKill(1, new SkillStop(user[1].getBulletPtr(), 10));

	return S_OK;
}

//=============================================================
//	## ���� ## release(void)
//=============================================================
void MainGame::release(void)
{
	GameNode::release();
	// �̹��� Ŭ���� ���� ������ ��� X
	// init�Լ����� �����Ҵ��� �޸𸮸� delete�� �������ش�.

	delete[] user;
}

//=============================================================
//	## ������Ʈ ## update(void)
//=============================================================
void MainGame::update(void)
{
	GameNode::update();
	// �̰����� ����, Ű����, ���콺 ��� ������Ʈ�� �Ѵ�
	// �����Ѱ� �̰����� �ڵ��Ѵٰ� �����ϸ� �ȴ�.

	if (user[0].getIsActive())
	{
		if (KEYMANAGER->isStayKeyDown(VK_LSHIFT))
		{
			user[0].shoot(user[0].getTeam() * 180.0f);
		}
		if (KEYMANAGER->isStayKeyDown('X'))
		{
			user[0].userSKill(1, user[0].getTeam() * 180.0f);
		}
		if (KEYMANAGER->isStayKeyDown('Z'))
		{
			user[0].userSKill(0, user[0].getTeam() * 180.0f);
		}
		if (KEYMANAGER->isStayKeyDown('W'))
			user[0].move(UP);
		if (KEYMANAGER->isStayKeyDown('S'))
			user[0].move(DOWN);
	}
	if (user[1].getIsActive())
	{
		if (KEYMANAGER->isStayKeyDown(VK_RSHIFT))
		{
			user[1].shoot(user[1].getTeam() * 180.0f);
		}
		if (KEYMANAGER->isStayKeyDown('O'))
		{
			user[1].userSKill(1, user[1].getTeam() * 180.0f);
		}
		if (KEYMANAGER->isStayKeyDown('P'))
		{
			user[1].userSKill(0, user[1].getTeam() * 180.0f);
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
			user[1].move(UP);
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
			user[1].move(DOWN);
	}


	user[0].bulletMove();
	user[0].moveSKill();
	user[0].collideSkill(user[1]);


	user[1].bulletMove();
	user[1].moveSKill();
	user[1].collideSkill(user[0]);


	for (int team = 0; team < 2; ++team)
	{
		for (int i = 0; i < user[team].getMaxBullet(); ++i)
		{
			if (user[team].getBullet(i).getIsActive())
			{
				if (user[team].getBullet(i).collide(user[(team + 1) % 2]))
				{

					user[team].getBullet(i).setIsActive(false);
					user[(team + 1) % 2].hitBullet();
				}
			}
		}
	}
}

//=============================================================
//	## ���� ## render(HDC hdc)
//=============================================================
void MainGame::render(HDC hdc)
{


	/*SetDCBrushColor(hdc, RGB(100, 0, 0));
	SelectObject(hdc, GetStockObject(DC_BRUSH));
	int r = RND->getFromIntTo(200, 256), g = RND->getFromIntTo(100, 256), b = RND->getFromIntTo(100, 256);*/

	user[0].bulletDraw(hdc);
	user[0].draw(hdc);
	user[0].drawSkill(hdc);

	user[1].bulletDraw(hdc);
	user[1].draw(hdc);
	user[1].drawSkill(hdc);

}

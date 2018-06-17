#pragma once
#include "GameNode.h"

class MainGame : public GameNode
{
private:
	Player * user;

public:
	virtual HRESULT init(void);	// void�� ����ص� ��. HRESULT: �������� ���� ���� ���� ���� ���� ���� �� ����. ���� ���� ����ϴ� ���� S_OK(���� ����), E_FAIL(���� �߻�)
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);

	MainGame() {}
	virtual ~MainGame() {}
};


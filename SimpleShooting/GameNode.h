#pragma once
class GameNode
{
public:
	virtual HRESULT init(void);	// void�� ����ص� ��. HRESULT: �������� ���� ���� ���� ���� ���� ���� �� ����. ���� ���� ����ϴ� ���� S_OK(���� ����), E_FAIL(���� �߻�)
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);

	// ���� ���ν���
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	GameNode() {}
	virtual ~GameNode() {} // �Ҹ��ڿ� virtual Ű���带 ���̴� ���� ������ �ܰ�����
};


#include "stdafx.h"
#include "GameNode.h"

//=============================================================
//	## �ʱ�ȭ ## init(void)
//=============================================================
HRESULT GameNode::init(void)
{
	SetTimer(_hWnd, 1, 10, NULL);			// Ÿ�̸� �ʱ�ȭ
	KEYMANAGER->init();						// Ű �Ŵ��� �ʱ�ȭ
	RND->init();
	return S_OK;
}

//=============================================================
//	## ���� ## release(void)
//=============================================================
void GameNode::release(void)
{
	KillTimer(_hWnd, 1);
	// Ű �Ŵ��� �̱��� ����
	KEYMANAGER->release();
	KEYMANAGER->releaseSingleton();
	RND->release();
	RND->releaseSingleton();
}

//=============================================================
//	## ������Ʈ ## update(void)
//=============================================================
void GameNode::update(void)
{
	// ���ΰ�ħ (���߿� ���� Ÿ�̸Ӹ� ���� �Ŀ��� ������� �ʴ´�.)
	// ������۸� ���� ������� �ʴ´�(true => false)
	InvalidateRect(_hWnd, NULL, TRUE);		// ture == TRUE
}

//=============================================================
//	## ���� ## render(HDC hdc)
//=============================================================
void GameNode::render(HDC hdc)
{

}

//=============================================================
//	## �������ν��� ##
//=============================================================
LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;	

	static POINT pt = { 0, 0 };

	switch (iMessage)
	{
	case WM_TIMER:
		this->update();
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		this->render(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:	//esc Ű�� ������ ȭ������
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

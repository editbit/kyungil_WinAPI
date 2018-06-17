#pragma once


//=============================================================
//	## singletonBase ## (�̱��� ����)
//=============================================================

template <typename T>
class SingletonBase
{
protected:
	// �̱��� �ν��Ͻ� ����
	static T* singleton;

	SingletonBase() {}
	virtual ~SingletonBase() {}

public:
	// �̱��� ��������
	static T* getSingleton(void);
	// �̱��� �޸𸮿��� �����ϱ�
	void releaseSingleton(void);


};
// �̱��� �ʱ�ȭ
template <typename T>
T* SingletonBase<T>::singleton = 0;

template<typename T>
inline T * SingletonBase<T>::getSingleton(void)
{
	// �̱����� ������ ���� ����
	if (!singleton)	singleton = new T;

	return singleton;
}

// �̱��� �޸𸮿��� ����
template<typename T>
inline void SingletonBase<T>::releaseSingleton(void)
{
	// �̱����� �������� ���� ����
	if (singleton)
	{
		delete singleton;
		singleton = 0;
	}
}

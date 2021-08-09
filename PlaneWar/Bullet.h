#pragma once
#include "DataStruct.h"

//�ӵ��ṹ��
struct SBullet
{
	SBullet();
	//�ӵ��ƶ��ӿ�
	void move(const int& nYOffset);
	//�ж��Ƿ�����ӵ�
	bool isExist(const int& nInRow, const int& nInCol) const;
	//��Ⱦ�ӵ�
	void onRender();

	SBulletData sBulletData;
	//�ӵ�λ��
	SData position;

	// ѭ��������
	int nTime;

	// �ӵ�����
	int nType;
	// �ӵ��˺�
	int bulletDamage;
};
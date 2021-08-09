#pragma once
#include "stdafx.h"
#include "Bullet.h"
using namespace std;
//�ӵ�������
struct SBulletMgr
{
	SBulletMgr();
	//���ݸ��£������ӵ��ƶ��ͻ���
	void onUpdate();
	//���һ���ӵ�
	void addBullet(const int& nInRow, const int& nInCol, const int& nInType, const int& nBulletDamage, const int& nBulletId);
	//���һ���ӵ�
	void addBullet(const SData& sData, const int& nBulletDamage, const int& nInType, const int& nBulletId);
	//����λ�÷���һ���ӵ�
	SBullet getBullet(const int& nInRow, const int& nInCol);
	//�ж����λ�����Ƿ��п��ӵ�
	bool isExist(const int& nInRow, const int& nInCol);
	//��ʼ������
	void initData();
	//�ͷż���
	void releaseSkills();
	//�������ӵ�
	vector<SBullet> vecBullets;
};

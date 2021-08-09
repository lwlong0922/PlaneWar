#pragma once
#include "stdafx.h"
#include "Bullet.h"
using namespace std;
//子弹管理者
struct SBulletMgr
{
	SBulletMgr();
	//数据更新，包括子弹移动和回收
	void onUpdate();
	//添加一颗子弹
	void addBullet(const int& nInRow, const int& nInCol, const int& nInType, const int& nBulletDamage, const int& nBulletId);
	//添加一颗子弹
	void addBullet(const SData& sData, const int& nBulletDamage, const int& nInType, const int& nBulletId);
	//根据位置返回一颗子弹
	SBullet getBullet(const int& nInRow, const int& nInCol);
	//判断这个位置上是否有颗子弹
	bool isExist(const int& nInRow, const int& nInCol);
	//初始化数据
	void initData();
	//释放技能
	void releaseSkills();
	//存放玩家子弹
	vector<SBullet> vecBullets;
};

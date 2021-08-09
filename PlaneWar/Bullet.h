#pragma once
#include "DataStruct.h"

//子弹结构体
struct SBullet
{
	SBullet();
	//子弹移动接口
	void move(const int& nYOffset);
	//判断是否存在子弹
	bool isExist(const int& nInRow, const int& nInCol) const;
	//渲染子弹
	void onRender();

	SBulletData sBulletData;
	//子弹位置
	SData position;

	// 循环计数器
	int nTime;

	// 子弹类型
	int nType;
	// 子弹伤害
	int bulletDamage;
};
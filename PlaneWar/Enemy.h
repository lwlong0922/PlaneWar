#pragma once
#include "DataStruct.h"
//敌人
struct SEnemy
{
	SEnemy();
	//设置位置
	void setPosition(const int& nInRow, const int& nInCol);
	//判断位置上是否有敌人
	bool isExist(const int& nInRow, const int& nInCol) const;
	//判断位置上是否有敌人
	bool isExist(const SData& position) const;

	//渲染敌人
	void onRender();
	//数据更新，包括敌人移动，生成子弹
	void onUpdate();
	//被攻击中,返回剩余血量
	int damage(const int& nDamage);
	//开火
	void fire();
	//敌人移动
	void move();
	void initEnemy(const int& id);

	SData arrEnemy[4];

	SEnemyData sEnemyData;

	//移动速度参数,计数器
	int nMoveTime;

	//开火计数器
	int nFireTime;
};

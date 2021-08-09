#pragma once
#include "stdafx.h"
#include "Enemy.h"
//敌人管理者
struct SEnemyMgr
{
	SEnemyMgr();
	//刷新数据，包括生成敌人和移动敌人
	void onUpdate();
	//移动敌人接口
	void allEnemyMove();
	//判断是否存在
	bool isExist(const int& nInRow, const int& nInCol);
	//返回该位置的敌人
	SEnemy getEnemy(const int& nInRow, const int& nInCol);
	//返回一个随机位置
	static int getRandPosition();
	//随机返回一个敌人
	static SEnemy getRandEnemy();
	//根据生成一个敌人
	static SEnemy generateAnEnemy(const int& nInId);
	//初始化数据
	void initData();
	void releaseSkills();
	//存放敌人
	vector<SEnemy> vecEnemies;
	//敌人生成参数
	int nGenerateInterval;
	int nGenerateTime;

	int nBunchTime;
	int nCurBunch;


};

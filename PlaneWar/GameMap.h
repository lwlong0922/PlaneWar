#pragma once
#include "Player.h"
#include "BulletMgr.h"
#include "EnemyMgr.h"
#include "DataStruct.h"
#include "PropsMgr.h"

//地图
struct SGameMap
{
	SGameMap();

	//数据更新，包括玩家，子弹。敌人数据更新，碰撞判断
	void onUpdate();
	//渲染所有数据
	void onRender();
	//检查碰撞
	void checkCollision();
	//检查失败
	void checkFailure();
	//初始化数据
	void initAllData();

	void checkWin();
	void nextMap();
	int nScore;

	SPlayer sPlayer;
	SBulletMgr sBulletMgr;
	SEnemyMgr sEnemyMgr;
	SPropsMgr sPropsMgr;

	SMapData curSMapData;
};


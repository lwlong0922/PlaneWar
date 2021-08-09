#pragma once
#include "GameMenu.h"
#include "GameMap.h"
#include "GameSet.h"
#include "GameTransition.h"
//游戏管理者
struct SGameMgr
{
	SGameMgr();
	//更新数据，切换游戏状态
	void onUpdate();
	//渲染场景
	void onRender();
	void drawScene();
	SGameMenu sGameMenu;
	SGameMap sGameMap;
	SGameSet sGameSet;
	SGameTransition sGameTransition;
	int nGameState;
};
#pragma once
#include "GameMenu.h"
#include "GameMap.h"
#include "GameSet.h"
#include "GameTransition.h"
//��Ϸ������
struct SGameMgr
{
	SGameMgr();
	//�������ݣ��л���Ϸ״̬
	void onUpdate();
	//��Ⱦ����
	void onRender();
	void drawScene();
	SGameMenu sGameMenu;
	SGameMap sGameMap;
	SGameSet sGameSet;
	SGameTransition sGameTransition;
	int nGameState;
};
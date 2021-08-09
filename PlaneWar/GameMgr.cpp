#include "stdafx.h"
#include "GameMgr.h"


SGameMgr::SGameMgr()
{
	nGameState = E_GAME_MENU;
}


void SGameMgr::onUpdate()
{
	if(E_GAME_MENU == nGameState)
	{
		sGameMenu.onUpdate();
	}
	else if(E_GAME_MAP == nGameState)
	{
		sGameMap.onUpdate();
	}
	else if(E_GAME_SET == nGameState)
	{
		sGameSet.onUpdate();
	}
	else if(E_GAME_TRANSITION == nGameState)
	{
		sGameTransition.onUpdate();
	}

}

void SGameMgr::onRender()
{
	if(E_GAME_MENU == nGameState)
	{
		sGameMenu.onRender();
	}
	else if(E_GAME_MAP == nGameState)
	{
		sGameMap.onRender();
	}
	else if(E_GAME_SET == nGameState)
	{
		sGameSet.onRender();
	}
	else if(E_GAME_TRANSITION == nGameState)
	{
		sGameTransition.onRender();
	}
	else if(E_GAME_EXIT == nGameState)
	{
		exit(0);
	}

}

void SGameMgr::drawScene()
{
	onUpdate();
	onRender();
}

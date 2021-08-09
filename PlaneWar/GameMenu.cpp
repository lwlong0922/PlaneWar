#include "stdafx.h"
#include "GameMenu.h"

SGameMenu::SGameMenu()
{
	nMenuState = E_MENU_START;
}

void SGameMenu::onUpdate()
{
	if(KEY_DOWN(VK_UP))
	{
		nMenuState--;
		if(nMenuState < 0)
			nMenuState = 2;
	}
	else if(KEY_DOWN(VK_DOWN))
	{
		nMenuState++;
		if(nMenuState > 2)
			nMenuState = 0;
	}
	if(KEY_DOWN(VK_RETURN))
	{
		if(E_MENU_START == nMenuState)
		{
			g_sGameMgr.nGameState = E_GAME_MAP;
		}
		else if(E_MENU_SET == nMenuState)
		{
			g_sGameMgr.nGameState = E_GAME_SET;
		}
		else if(E_MENU_EXIT == nMenuState)
		{
			g_sGameMgr.nGameState = E_GAME_EXIT;
		}
	}
}

void SGameMenu::onRender() const
{
	if(E_MENU_START == nMenuState)
	{
		cout << "-> 游戏开始" << endl;
		cout << "   游戏设置" << endl;
		cout << "   游戏结束" << endl;
	}
	else if(E_MENU_SET == nMenuState)
	{
		cout << "   游戏开始" << endl;
		cout << "-> 游戏设置" << endl;
		cout << "   游戏结束" << endl;
	}
	else if(E_MENU_EXIT == nMenuState)
	{
		cout << "   游戏开始" << endl;
		cout << "   游戏设置" << endl;
		cout << "-> 游戏结束" << endl;
	}
}

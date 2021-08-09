#include "stdafx.h"
#include "GameSet.h"

SGameSet::SGameSet()
{
	vecSPlayerData = g_sDataMgr.sPlayerDataMgr.vecSPlayerData;
	nSelectIndex = 0;
}

void SGameSet::onUpdate()
{
	if(KEY_DOWN(VK_ESCAPE))
	{
		g_sGameMgr.nGameState = E_GAME_MENU;
	}
	else if(KEY_DOWN(VK_UP))
	{
		nSelectIndex--;
		if(nSelectIndex < 0)
		{
			nSelectIndex = vecSPlayerData.size() - 1;
		}
	}
	else if(KEY_DOWN(VK_DOWN))
	{
		nSelectIndex++;
		if(nSelectIndex == vecSPlayerData.size())
		{
			nSelectIndex = 0;
		}
	}
	else if(KEY_DOWN(VK_RETURN))
	{
		g_sGameMgr.nGameState = E_GAME_MAP;
		g_sGameMgr.sGameMap.initAllData();
		g_sGameMgr.sGameMap.sPlayer.initDate(vecSPlayerData[nSelectIndex].nId);
	}
}

void SGameSet::onRender()
{
	cout << "  角色名\t血量\t蓝量\t攻击力\t防御力" << endl;
	for(int i = 0; i < vecSPlayerData.size(); i++)
	{
		if(nSelectIndex == i)
		{
			cout << "->";
		}
		else
		{
			cout << "  ";
		}
		cout << vecSPlayerData[i].strName << "\t"
			<< vecSPlayerData[i].nMaxHp << "\t"
			<< vecSPlayerData[i].nMaxMp << "\t"
			<< vecSPlayerData[i].nAtk << "\t"
			<< vecSPlayerData[i].nDef << endl;
	}
}

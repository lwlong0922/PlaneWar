#include "stdafx.h"
#include "Player.h"


SPlayer::SPlayer() : arrPlayer {}
{
	initDate(2001);
}

void SPlayer::onUpdate()
{
	onBackUp();
	if(KEY_DOWN(VK_CONTROL))
	{
		releaseSkills();
	}

	if(KEY_DOWN(VK_RIGHT))
	{
		for(int i = 0; i < 4; i++)
		{
			arrPlayer[i].nCol++;
		}
	}
	if(KEY_DOWN(VK_LEFT))
	{
		for(int i = 0; i < 4; i++)
		{
			arrPlayer[i].nCol--;
		}
	}
	if(KEY_DOWN(VK_UP))
	{
		for(int i = 0; i < 4; i++)
		{
			arrPlayer[i].nRow--;
		}
	}
	if(KEY_DOWN(VK_DOWN))
	{
		for(int i = 0; i < 4; i++)
		{
			arrPlayer[i].nRow++;
		}
	}
	for(int i = 0; i < 4; i++)
	{
		if(1 == g_sGameMgr.sGameMap.curSMapData.arrMap[arrPlayer[i].nRow][arrPlayer[i].nCol])
		{
			onRestore();
		}
	}
	if(nFireTime++ == nFireInterval)
	{
		SBulletMgr& sBulletMgr = g_sGameMgr.sGameMap.sBulletMgr;
		bIsFire = false;
		sBulletMgr.addBullet(arrPlayer[1], sPlayerData.nAtk, E_BULLET_PLAYER, sPlayerData.nBulletId);
		nFireTime = 0;
	}

	if(nExp >= nLevel * 100)
	{
		nExp -= nLevel * 100;
		nLevel++;
		sPlayerData.nAtk *= 1.1;
		sPlayerData.nMaxHp *= 1.1;
		sPlayerData.nHp = sPlayerData.nMaxHp;
		sPlayerData.nMaxMp *= 1.1;
		sPlayerData.nMp = sPlayerData.nMaxMp;
		sPlayerData.nDef *= 1.1;
	}
}

void SPlayer::onRender() const
{
	cout << sPlayerData.strPic;
}

void SPlayer::onBackUp()
{
	for(int i = 0; i < 4; i++)
		arrPlayer[i].onBackUp();
}

void SPlayer::onRestore()
{
	for(int i = 0; i < 4; i++)
		arrPlayer[i].onRestore();
}

void SPlayer::releaseSkills()
{
	if(sPlayerData.nMp > sPlayerData.nMaxMp / 3)
	{
		sPlayerData.nMp -= sPlayerData.nMaxMp / 3;
		g_sGameMgr.sGameMap.sBulletMgr.releaseSkills();
		g_sGameMgr.sGameMap.sEnemyMgr.releaseSkills();
	}
}

void SPlayer::setPosition(const int& nInRow, const int& nInCol)
{
	arrPlayer[0].nRow = nInRow;
	arrPlayer[0].nCol = nInCol;
	arrPlayer[1].nRow = nInRow - 1;
	arrPlayer[1].nCol = nInCol;
	arrPlayer[2].nRow = nInRow;
	arrPlayer[2].nCol = nInCol - 1;
	arrPlayer[3].nRow = nInRow;
	arrPlayer[3].nCol = nInCol + 1;
}

bool SPlayer::isExist(const int& nInRow, const int& nInCol) const
{
	for(int i = 0; i < 4; i++)
	{
		if(arrPlayer[i].isExist(nInRow, nInCol))
		{
			return true;
		}
	}
	return false;
}

bool SPlayer::isExist(const SData& sInData) const
{
	return isExist(sInData.nRow, sInData.nCol);
}

void SPlayer::initDate(const int nInId)
{
	sPlayerData = g_sDataMgr.sPlayerDataMgr.getDataById(nInId);
	sPlayerData.nHp = sPlayerData.nMaxHp;
	sPlayerData.nMp = sPlayerData.nMaxMp;
	nFireTime = 0;
	nExp = 0;
	nLevel = 1;
	bIsFire = false;
	nFireInterval = 1;
}

void SPlayer::propsToStrengthen(const SProps& sProps)
{
	sPlayerData.nMaxHp += sProps.sPropsData.nMaxHp;
	sPlayerData.nMaxMp += sProps.sPropsData.nMaxMp;
	sPlayerData.nAtk += sProps.sPropsData.nAtk;
	sPlayerData.nDef += sProps.sPropsData.nDef;
	sPlayerData.nHp += sProps.sPropsData.nHp;
	sPlayerData.nMp += sProps.sPropsData.nMp;
	sPlayerData.nHp = sPlayerData.nHp > sPlayerData.nMaxHp ? sPlayerData.nMaxHp : sPlayerData.nHp;
	sPlayerData.nMp = sPlayerData.nMp > sPlayerData.nMaxMp ? sPlayerData.nMaxMp : sPlayerData.nMp;
}

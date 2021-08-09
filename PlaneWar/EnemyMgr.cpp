#include "stdafx.h"
#include "EnemyMgr.h"
SEnemyMgr::SEnemyMgr()
{
	initData();
}


void SEnemyMgr::onUpdate()
{

	for(int i = 0; i < vecEnemies.size(); i++)
	{
		if(vecEnemies[i].sEnemyData.nHp <= 0)
		{
			g_sGameMgr.sGameMap.sPlayer.nExp += vecEnemies[i].sEnemyData.nExp;
			g_sGameMgr.sGameMap.sPropsMgr.randGenerateProp(vecEnemies[i].arrEnemy[0].nRow, vecEnemies[i].arrEnemy[0].nCol);
			vecEnemies.erase(vecEnemies.begin() + i--);
		}
	}

	if(nGenerateInterval == nGenerateTime++)
	{
		nGenerateTime = 0;
		SEnemy& sEnemy = getRandEnemy();
		vecEnemies.push_back(sEnemy);
	}
	if(nBunchTime++ == g_sGameMgr.sGameMap.curSMapData.nBunchInTime)
	{
		if(nCurBunch < g_sGameMgr.sGameMap.curSMapData.vecBunch.size())
		{
			nBunchTime = 0;
			vector<SBunch> vecBunch = g_sGameMgr.sGameMap.curSMapData.vecBunch[nCurBunch];
			for(int i = 0; i < vecBunch.size(); i++)
			{
				for(int j = 0; j < vecBunch[i].nEnemyCnt; j++)
				{
					SEnemy& sEnemy = generateAnEnemy(vecBunch[i].nEnemyId);
					vecEnemies.push_back(sEnemy);
				}
			}
			nCurBunch++;
		}
		if(nCurBunch == g_sGameMgr.sGameMap.curSMapData.vecBunch.size() - 1)
		{
			nGenerateInterval = 999999999;
		}
	}


	allEnemyMove();
}


void SEnemyMgr::allEnemyMove()
{
	for(auto& sEnemy : vecEnemies)
	{
		sEnemy.onUpdate();
	}
	for(unsigned int i = 0; i < vecEnemies.size(); i++)
	{
		if(vecEnemies[i].arrEnemy[0].nRow > g_sGameMgr.sGameMap.curSMapData.nRowSize)
		{
			vecEnemies.erase(vecEnemies.begin() + i--);
		}
	}
}

bool SEnemyMgr::isExist(const int& nInRow, const int& nInCol)
{
	for(SEnemy sEnemy : vecEnemies)
	{

		if(sEnemy.isExist(nInRow, nInCol))
		{
			return true;
		}
	}
	return false;
}

SEnemy SEnemyMgr::getEnemy(const int& nInRow, const int& nInCol)
{
	SEnemy sEnemyTemp;
	for(SEnemy& sEnemy : vecEnemies)
	{

		if(sEnemy.isExist(nInRow, nInCol))
		{
			sEnemyTemp = sEnemy;
			return sEnemyTemp;
		}
	}
	return sEnemyTemp;
}

int SEnemyMgr::getRandPosition()
{
	return rand() % (g_sGameMgr.sGameMap.curSMapData.nColSize - 4) + 2;
}

SEnemy SEnemyMgr::getRandEnemy()
{

	SMapData curSMapData = g_sGameMgr.sGameMap.curSMapData;
	int nSum = 0;
	for(int i = 0; i < curSMapData.nEnemyTypeCnt; i++)
	{
		nSum += curSMapData.vecEnemyProbability[i];
	}
	int tempRand = rand() % nSum + 1;
	for(int i = 0; i < curSMapData.nEnemyTypeCnt; i++)
	{
		if(tempRand <= curSMapData.vecEnemyProbability[i])
		{
			return generateAnEnemy(curSMapData.vecEnemyId[i]);
		}
		tempRand -= curSMapData.vecEnemyProbability[i];
	}


	return SEnemy();
}

SEnemy SEnemyMgr::generateAnEnemy(const int& nInId)
{
	SEnemy sEnemy;
	sEnemy.initEnemy(nInId);
	sEnemy.setPosition(-2, getRandPosition());
	return sEnemy;
}

void SEnemyMgr::initData()
{
	vecEnemies.clear();
	nGenerateTime = 0;
	nGenerateInterval = 10;
	nBunchTime = 0;
	nCurBunch = 0;
}

void SEnemyMgr::releaseSkills()
{
	for(int i = 0; i < vecEnemies.size(); i++)
	{
		vecEnemies[i].sEnemyData.nHp -= g_sGameMgr.sGameMap.sPlayer.sPlayerData.nMp * 5;
	}
}






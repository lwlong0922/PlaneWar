#include "stdafx.h"
#include "Enemy.h"

SEnemy::SEnemy()
{
	initEnemy(3001);
}

void SEnemy::setPosition(const int& nInRow, const int& nInCol)
{
	arrEnemy[0].nRow = nInRow;
	arrEnemy[0].nCol = nInCol;
	arrEnemy[1].nRow = nInRow + 1;
	arrEnemy[1].nCol = nInCol;
	arrEnemy[2].nRow = nInRow;
	arrEnemy[2].nCol = nInCol - 1;
	arrEnemy[3].nRow = nInRow;
	arrEnemy[3].nCol = nInCol + 1;
}

bool SEnemy::isExist(const int& nInRow, const int& nInCol) const
{
	for(int i = 0; i < 4; i++)
	{
		if(nInRow == arrEnemy[i].nRow&&nInCol == arrEnemy[i].nCol)
		{
			return true;
		}
	}
	return false;
}

bool SEnemy::isExist(const SData& position) const
{
	return isExist(position.nRow, position.nCol);
}

void SEnemy::onRender()
{
	cout << sEnemyData.strPic;
}

void SEnemy::onUpdate()
{
	fire();
	move();
}

int SEnemy::damage(const int& nDamage)
{
	sEnemyData.nHp -= nDamage;
	return sEnemyData.nHp;
}

void SEnemy::fire()
{
	if(nFireTime++ > sEnemyData.nFireInterval)
	{
		nFireTime = 0;
		g_sGameMgr.sGameMap.sBulletMgr.addBullet(arrEnemy[1], sEnemyData.nAtk, E_BULLET_ENEMY, sEnemyData.nBulletId);
	}
}

void SEnemy::move()
{
	if(nMoveTime++ == sEnemyData.nMoveInterval)
	{
		nMoveTime = 0;
		for(int i = 0; i < 4; i++)
			arrEnemy[i].nRow++;
		if(g_sGameMgr.sGameMap.sEnemyMgr.nCurBunch == g_sGameMgr.sGameMap.curSMapData.vecBunch.size())
		{
			int nTargetCol = g_sGameMgr.sGameMap.sPlayer.arrPlayer[0].nCol;
			int nDiffCol = arrEnemy[0].nCol - nTargetCol;
			if(nDiffCol<0)
			{
				setPosition(arrEnemy[0].nRow, arrEnemy[0].nCol + 1);
			}
			else if(nDiffCol>0)
			{
				setPosition(arrEnemy[0].nRow, arrEnemy[0].nCol - 1);
			}
		}
	}


}

void SEnemy::initEnemy(const int& id)
{
	sEnemyData = g_sDataMgr.sEnemyDataMgr.getDataById(id);
	sEnemyData.nHp = sEnemyData.nMaxHp;
	sEnemyData.nMp = sEnemyData.nMaxMp;
	nMoveTime = 0;
	nFireTime = 0;
	setPosition(-1, -1);
}

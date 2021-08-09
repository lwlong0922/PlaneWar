#include "stdafx.h"
#include "BulletMgr.h"


SBulletMgr::SBulletMgr()
{
	initData();
}

void SBulletMgr::onUpdate()
{
	for(auto& sBullet : vecBullets)
	{
		if(sBullet.nType == E_BULLET_PLAYER)
		{
			sBullet.move(-1);
		}
		else if(sBullet.nType == E_BULLET_ENEMY)
		{
			sBullet.move(1);
		}

	}
	for(unsigned int i = 0; i < vecBullets.size(); i++)
	{
		if(vecBullets[i].nType == E_BULLET_PLAYER)
		{
			if(vecBullets[i].position.nRow <= 0)
			{
				vecBullets.erase(vecBullets.begin() + i--);
			}
		}
		else if(vecBullets[i].nType == E_BULLET_ENEMY)
		{
			if(vecBullets[i].position.nRow > g_sGameMgr.sGameMap.curSMapData.nRowSize)
			{
				vecBullets.erase(vecBullets.begin() + i--);
			}
		}
	}
}


void SBulletMgr::addBullet(const int& nInRow, const int& nInCol, const int& nInType, const int& nBulletDamage, const int& nBulletId)
{
	SBullet sBullet;
	sBullet.position.nRow = nInRow;
	sBullet.position.nCol = nInCol;
	sBullet.nType = nInType;
	sBullet.bulletDamage = nBulletDamage;
	sBullet.sBulletData = g_sDataMgr.sBulletDataMgr.getDataById(nBulletId);
	vecBullets.push_back(sBullet);
}

void SBulletMgr::addBullet(const SData& sData, const int& nBulletDamage, const int& nInType, const int& nBulletId)
{
	addBullet(sData.nRow, sData.nCol, nInType, nBulletDamage, nBulletId);
}

SBullet SBulletMgr::getBullet(const int& nInRow, const int& nInCol)
{
	SBullet sBullet;
	for(int i = 0; i < vecBullets.size(); i++)
	{
		if(vecBullets[i].isExist(nInRow, nInCol))
		{
			sBullet = vecBullets[i];
			break;
		}
	}
	return sBullet;
}

bool SBulletMgr::isExist(const int& nInRow, const int& nInCol)
{
	for(const auto sBullet : vecBullets)
	{
		if(sBullet.position.nCol == nInCol && sBullet.position.nRow == nInRow)
		{
			return true;
		}
	}
	return false;
}

void SBulletMgr::initData()
{
	vecBullets.clear();
}

void SBulletMgr::releaseSkills()
{
	for(int i = 0; i < vecBullets.size(); i++)
	{
		if(vecBullets[i].nType == E_BULLET_ENEMY)
		{
			vecBullets.erase(vecBullets.begin() + i--);
		}
	}
}


#include "stdafx.h"
#include "Bullet.h"


SBullet::SBullet()
{
	bulletDamage = 0;
	sBulletData.nTotalTime = 1;
	nTime = 0;
	position.nRow = 0;
	position.nCol = 0;
}

void SBullet::move(const int& nYOffset)
{
	if(nTime++ == sBulletData.nTotalTime)
	{
		nTime = 0;
		position.nRow += nYOffset;
	}
}

bool SBullet::isExist(const int& nInRow, const int& nInCol) const
{
	if(position.nRow == nInRow&&position.nCol == nInCol)
	{
		return true;
	}
	return false;
}

void SBullet::onRender()
{
	cout << sBulletData.strPic;
}

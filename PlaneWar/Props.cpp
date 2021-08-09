#include "stdafx.h"
#include "Props.h"

SProps::SProps()
{
	sData.nRow = -1;
	sData.nCol = -1;
	nMoveTimes = 0;
}

void SProps::setPositions(const int& nInRow, const int& nInCol)
{
	sData.nRow = nInRow;
	sData.nCol = nInCol;
}

void SProps::move()
{
	if(nMoveTimes++ > sPropsData.nMoveInterval)
	{
		nMoveTimes = 0;
		sData.nRow++;
	}
}

void SProps::init(const int& nInId)
{
	sPropsData = g_sDataMgr.sPropsDataMgr.getDataById(nInId);
	sData.nRow = -1;
	sData.nCol = -1;
	nMoveTimes = 0;
}

void SProps::onRender()
{
	cout << sPropsData.strPic;
}

bool SProps::isExist(const int& nInRow, const int& nInCol)
{
	if(sData.nRow == nInRow &&sData.nCol == nInCol)
	{
		return true;
	}
	return false;
}

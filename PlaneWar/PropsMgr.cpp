#include "stdafx.h"
#include "PropsMgr.h"

SPropsMgr::SPropsMgr()
{
}

void SPropsMgr::init()
{
	vecSProps.clear();
}

void SPropsMgr::move()
{
	for(auto& sProps : vecSProps)
	{
		sProps.move();

	}
	for(int i = 0; i < vecSProps.size(); i++)
	{
		if(vecSProps[i].sData.nRow>g_sGameMgr.sGameMap.curSMapData.nRowSize)
		{
			vecSProps.erase(vecSProps.begin() + i--);
		}
	}
}

void SPropsMgr::onUpdate()
{
	move();
}

SProps SPropsMgr::getSProps(const int& nInRow, const int& nInCol)
{
	for(auto& sProps : vecSProps)
	{
		if(nInRow == sProps.sData.nRow&&nInCol == sProps.sData.nCol)
		{
			return sProps;
		}
	}
	return SProps();
}


SProps SPropsMgr::generateProp(const int& nInId)
{
		SProps sProps;
		sProps.init(nInId);
		return sProps;

}

void SPropsMgr::randGenerateProp(const int& nInRow, const int& nInCol)
{

	if(rand() % 100 < g_sDataMgr.sPropsDataMgr.nProb)
	{
		vector<SPropsData> vecPropsData = g_sDataMgr.sPropsDataMgr.vecSPropsData;
		int sum = 0;
		for(int i = 0; i < vecPropsData.size(); i++)
		{
			sum += vecPropsData[i].nProb;
		}
		int nTempRand = rand() % sum ;
		for(int i = 0; i < vecPropsData.size(); i++)
		{
			if(nTempRand <= vecPropsData[i].nProb)
			{
				SProps& sProps = generateProp(vecPropsData[i].nId);
				sProps.setPositions(nInRow, nInCol);
				vecSProps.push_back(sProps);
				break;
			}
			nTempRand -= vecPropsData[i].nProb;
		}
	}
}


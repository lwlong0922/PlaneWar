#include "stdafx.h"
#include "DataStruct.h"

void SData::onBackUp()
{
	nRowBk = nRow;
	nColBk = nCol;
}

void SData::onRestore()
{
	nRow = nRowBk;
	nCol = nColBk;
}

bool SData::isExist(const int& nInRow, const int& nInCol) const
{
	return nRow == nInRow && nCol == nInCol;
}

SMapData::SMapData()
{
	nId = 0;
	nColSize = 0;
	nRowSize = 0;
	nInitCol = 0;
	nInitRow = 0;
	strName = "";
}

SMapDataMgr::SMapDataMgr()
{
}

void SMapDataMgr::loadData(const std::string& strPath)
{
	fstream fin(strPath);
	if(fin)
	{
		getline(fin, string());
		int nCount;
		fin >> nCount;
		for(int i = 0; i < nCount; i++)
		{
			int nBunch;
			SMapData sMapData;
			fin >> sMapData.nId >> sMapData.nInitRow >> sMapData.nInitRow
				>> sMapData.nRowSize >> sMapData.nColSize >> sMapData.strName >> sMapData.nEnemyTypeCnt >> nBunch;
			for(int j = 0; j < sMapData.nEnemyTypeCnt; j++)
			{
				int nTempId;
				fin >> nTempId;
				sMapData.vecEnemyId.push_back(nTempId);
			}
			for(int j = 0; j < sMapData.nEnemyTypeCnt; j++)
			{
				int nTempProbability;
				fin >> nTempProbability;
				sMapData.vecEnemyProbability.push_back(nTempProbability);
			}

			for(int j = 0; j < nBunch; j++)
			{
				int nTypeCnt;
				fin >> nTypeCnt;
				vector<SBunch> vecTemp;
				for(int k = 0; k < nTypeCnt; k++)
				{
					SBunch sBunch;
					fin >> sBunch.nEnemyId;
					fin >> sBunch.nEnemyCnt;
					vecTemp.push_back(sBunch);
				}
				sMapData.vecBunch.push_back(vecTemp);
			}

			//ªÊ÷∆µÿÕº
			for(int j = 0; j < sMapData.nRowSize; j++)
			{
				for(int k = 0; k < sMapData.nColSize; k++)
				{
					if(j != 0 && j != sMapData.nRowSize - 1 && k != 0 && k != sMapData.nColSize - 1)
						sMapData.arrMap[j][k] = 0;
					else
						sMapData.arrMap[j][k] = 1;
				}
			}
			sMapData.nBunchInTime = 400;
			vecSMapData.push_back(sMapData);
		}
	}
}

SMapData SMapDataMgr::getDataById(const int& nInId)
{
	for(auto& sMapData : vecSMapData)
	{
		if(sMapData.nId == nInId)
			return sMapData;
	}
	return SMapData();
}

SPlayerDataMgr::SPlayerDataMgr()
{
}

void SPlayerDataMgr::loadData(const std::string& strPath)
{
	fstream fin(strPath);
	if(fin)
	{
		getline(fin, string());
		int nCount;
		fin >> nCount;
		for(int i = 0; i < nCount; i++)
		{
			SPlayerData sPlayerData;
			fin >> sPlayerData.nId >> sPlayerData.strName >> sPlayerData.nMaxHp
				>> sPlayerData.nMaxMp >> sPlayerData.nAtk >> sPlayerData.nDef
				>> sPlayerData.strPic >> sPlayerData.nBulletId;
			vecSPlayerData.push_back(sPlayerData);
		}
	}
}

SPlayerData SPlayerDataMgr::getDataById(const int& nInId)
{
	for(auto& sPlayerData : vecSPlayerData)
	{
		if(sPlayerData.nId == nInId)
			return sPlayerData;
	}
	return SPlayerData();
}

SEnemyDataMgr::SEnemyDataMgr()
{
}

void SEnemyDataMgr::loadData(const std::string& strPath)
{
	fstream fin(strPath);
	if(fin)
	{
		getline(fin, string());
		int nCount;
		fin >> nCount;
		for(int i = 0; i < nCount; i++)
		{
			SEnemyData sEnemyData;
			fin >> sEnemyData.nId >> sEnemyData.nMaxHp >> sEnemyData.nMaxMp
				>> sEnemyData.nAtk >> sEnemyData.nDef >> sEnemyData.strPic
				>> sEnemyData.nMoveInterval >> sEnemyData.nFireInterval
				>> sEnemyData.nBulletId >> sEnemyData.nExp;
			vecSEnemyData.push_back(sEnemyData);
		}
	}
}

SEnemyData SEnemyDataMgr::getDataById(const int& nInId)
{
	for(auto& sEnemyData : vecSEnemyData)
	{
		if(sEnemyData.nId == nInId)
			return sEnemyData;
	}
	return SEnemyData();
}

SBulletDataMgr::SBulletDataMgr()
{
}

void SBulletDataMgr::loadData(const std::string& strPath)
{
	fstream fin(strPath);
	if(fin)
	{
		getline(fin, string());
		int nCount;
		fin >> nCount;
		for(int i = 0; i < nCount; i++)
		{
			SBulletData sBulletData;
			fin >> sBulletData.nId >> sBulletData.strPic >> sBulletData.nTotalTime;
			vecSBulletData.push_back(sBulletData);
		}
	}
}

SBulletData SBulletDataMgr::getDataById(const int& nInId)
{
	for(auto& sBulletData : vecSBulletData)
	{
		if(sBulletData.nId == nInId)
			return sBulletData;
	}
	return SBulletData();
}

SPropsData::SPropsData()
{
	nId = -1;
}

SPropsDataMgr::SPropsDataMgr()
{
}

void SPropsDataMgr::loadData(const string& strPath)
{
	fstream fin(strPath);
	if(fin)
	{
		getline(fin, string());
		int nCount;;
		fin >> nCount >> nProb;
		for(int i = 0; i < nCount; i++)
		{
			SPropsData sPropsData;
			fin >> sPropsData.nId
				>> sPropsData.nMaxHp
				>> sPropsData.nMaxMp
				>> sPropsData.nHp
				>> sPropsData.nMp
				>> sPropsData.nAtk
				>> sPropsData.nDef
				>> sPropsData.strPic
				>> sPropsData.nProb
				>> sPropsData.nMoveInterval;
			vecSPropsData.push_back(sPropsData);
		}
	}
}

SPropsData SPropsDataMgr::getDataById(const int& nInId)
{
	for(auto& sPropsData : vecSPropsData)
	{
		if(sPropsData.nId == nInId)
			return sPropsData;
	}
	return SPropsData();
}

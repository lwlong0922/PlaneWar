#pragma once
//基础数据
using namespace std;
struct SData
{
	//备份位置
	void onBackUp();
	//还原位置
	void onRestore();
	//判断是否在点上
	bool isExist(const int& nInRow, const int& nInCol) const;

	int nRow;
	int nCol;
	int nRowBk;
	int nColBk;
};

struct SBunch
{
	int nEnemyId;
	int nEnemyCnt;
};

struct SMapData
{
	SMapData();
	int nId;
	int nInitRow;
	int nInitCol;
	int nRowSize;
	int nColSize;
	int arrMap[100][100];
	int nEnemyTypeCnt;
	int nBunchInTime;
	vector<vector<SBunch>> vecBunch;
	vector<int> vecEnemyId;
	vector<int> vecEnemyProbability;
	string strName;
};

struct SMapDataMgr
{
	//加载数据
	SMapDataMgr();
	void loadData(const string& strPath);
	//根据地图ID返回SMapData
	SMapData getDataById(const int& nInId);
	vector<SMapData> vecSMapData;

};


struct SPlayerData
{
	int nId;
	int nHp;
	int nMp;
	int nMaxHp;
	int nMaxMp;
	int nAtk;
	int nDef;
	int nBulletId;
	string strName;
	string strPic;
};

struct SPlayerDataMgr
{
	//加载数据
	SPlayerDataMgr();
	void loadData(const string& strPath);
	//根据地图ID返回SMapData
	SPlayerData getDataById(const int& nInId);
	vector<SPlayerData> vecSPlayerData;
};

struct SEnemyData
{
	int nId;
	int nHp;
	int nMp;
	int nMaxHp;
	int nMaxMp;
	int nAtk;
	int nDef;
	//移动速度参数，总次数
	int nMoveInterval;
	//开火
	int nFireInterval;
	int nBulletId;
	int nExp;
	string strPic;
};

struct SEnemyDataMgr
{
	//加载数据
	SEnemyDataMgr();
	void loadData(const string& strPath);
	//根据地图ID返回SMapData
	SEnemyData getDataById(const int& nInId);
	vector<SEnemyData> vecSEnemyData;
};


struct SBulletData
{
	int nId;
	string strPic;
	// 循环nTotalTime次多少移动一次，
	int nTotalTime;
};

struct SBulletDataMgr
{
	//加载数据
	SBulletDataMgr();
	void loadData(const string& strPath);
	//根据地图ID返回SMapData
	SBulletData getDataById(const int& nInId);
	vector<SBulletData> vecSBulletData;
};

struct SPropsData
{
	SPropsData();
	int nId;
	int nMaxHp;
	int nMaxMp;
	int nHp;
	int nMp;
	int nAtk;
	int nDef;
	int nMoveInterval;
	string strPic;
	int nProb;
};

struct SPropsDataMgr
{
	SPropsDataMgr();
	void loadData(const string& strPath);
	//根据地图ID返回SMapData
	SPropsData getDataById(const int& nInId);
	vector<SPropsData> vecSPropsData;
	int nProb;
};
#pragma once
//��������
using namespace std;
struct SData
{
	//����λ��
	void onBackUp();
	//��ԭλ��
	void onRestore();
	//�ж��Ƿ��ڵ���
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
	//��������
	SMapDataMgr();
	void loadData(const string& strPath);
	//���ݵ�ͼID����SMapData
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
	//��������
	SPlayerDataMgr();
	void loadData(const string& strPath);
	//���ݵ�ͼID����SMapData
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
	//�ƶ��ٶȲ������ܴ���
	int nMoveInterval;
	//����
	int nFireInterval;
	int nBulletId;
	int nExp;
	string strPic;
};

struct SEnemyDataMgr
{
	//��������
	SEnemyDataMgr();
	void loadData(const string& strPath);
	//���ݵ�ͼID����SMapData
	SEnemyData getDataById(const int& nInId);
	vector<SEnemyData> vecSEnemyData;
};


struct SBulletData
{
	int nId;
	string strPic;
	// ѭ��nTotalTime�ζ����ƶ�һ�Σ�
	int nTotalTime;
};

struct SBulletDataMgr
{
	//��������
	SBulletDataMgr();
	void loadData(const string& strPath);
	//���ݵ�ͼID����SMapData
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
	//���ݵ�ͼID����SMapData
	SPropsData getDataById(const int& nInId);
	vector<SPropsData> vecSPropsData;
	int nProb;
};
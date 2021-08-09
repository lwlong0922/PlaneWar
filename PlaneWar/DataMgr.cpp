#include "stdafx.h"
#include "DataMgr.h"

SDataMgr::SDataMgr()
{
	sMapDataMgr.loadData("MapDt.txt");
	sPlayerDataMgr.loadData("PlayerDt.txt");
	sEnemyDataMgr.loadData("EnemyDt.txt");
	sBulletDataMgr.loadData("BulletDt.txt");
	sPropsDataMgr.loadData("PropsDt.txt");
}

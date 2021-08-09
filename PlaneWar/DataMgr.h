#pragma once
#include "DataStruct.h"
struct SDataMgr
{
	SDataMgr();
	SMapDataMgr sMapDataMgr;
	SPlayerDataMgr sPlayerDataMgr;
	SEnemyDataMgr sEnemyDataMgr;
	SBulletDataMgr sBulletDataMgr;
	SPropsDataMgr sPropsDataMgr;
};

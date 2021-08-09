#pragma once
#include "DataStruct.h"

struct SProps;

//玩家
struct SPlayer
{
	SPlayer();
	//数据更新，控制玩家移动和发射子弹
	void onUpdate();
	//渲染玩家
	void onRender() const;
	//备份数据
	void onBackUp();
	//还原数据
	void onRestore();
	void releaseSkills();
	//设置位置
	void setPosition(const int& nInRow, const int& nInCol);
	//判断敌人是否存在
	bool isExist(const int& nInRow, const int& nInCol) const;
	//判断敌人是否存在
	bool isExist(const SData& sInData) const;
	//初始化数据
	void initDate(int nInId);
	//道具强化
	void propsToStrengthen(const SProps& sProps);

	SPlayerData sPlayerData;

	int nFireInterval;
	int nFireTime;
	int nExp;
	int nLevel;
	bool bIsFire;
	SData arrPlayer[4];
};

#pragma once
//���ý���
struct SGameSet
{
	SGameSet();
	void onUpdate();
	void onRender();
	int nSelectIndex;
	vector<SPlayerData> vecSPlayerData;
};


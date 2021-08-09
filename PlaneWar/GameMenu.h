#pragma once
//目录
struct SGameMenu
{
	SGameMenu();
	//更新数据
	void onUpdate();
	//渲染
	void onRender() const;
	int nMenuState;
};


#pragma once

struct SProps
{
	SProps();
	void setPositions(const int& nInRow, const int& nInCol);
	void move();
	void init(const int& nInId);
	void onRender();
	bool isExist(const int& nInRow, const int& nInCol);
	SPropsData sPropsData;
	SData sData;
	int nMoveTimes;
};

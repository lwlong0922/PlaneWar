#pragma once
#include "Props.h"

struct SPropsMgr
{
	SPropsMgr();
	void init();
	void move();
	void onUpdate();
	SProps getSProps(const int& nInRow, const int& nInCol);
	SProps generateProp(const int& nInId);
	void randGenerateProp(const int& nInRow, const int& nInCol);
	vector<SProps> vecSProps;
};

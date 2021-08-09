#pragma once
using namespace std;
struct SGameTransition
{
	SGameTransition();
	void onUpdate();
	void onRender();
	string	str;
	int nextState;
};

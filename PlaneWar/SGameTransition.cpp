#include "stdafx.h"
#include "GameTransition.h"

SGameTransition::SGameTransition()
{
	str = "\n\tNULL\n\n";
}

void SGameTransition::onUpdate()
{
	if(KEY_DOWN(VK_RETURN))
	{
		g_sGameMgr.nGameState = nextState;
	}
}

void SGameTransition::onRender()
{
	cout << str;
}

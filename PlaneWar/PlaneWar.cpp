// PlaneWar.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"


SDataMgr g_sDataMgr;
SGameMgr g_sGameMgr;

int _tmain(int argc, _TCHAR* argv[])
{
	 HANDLE hOutput;
	 COORD coord = { 0, 0 };
	 hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	 HANDLE hOutBuf = CreateConsoleScreenBuffer(
	 	GENERIC_READ | GENERIC_WRITE,
	 	FILE_SHARE_READ | FILE_SHARE_WRITE,
	 	NULL,
	 	CONSOLE_TEXTMODE_BUFFER,
	 	NULL
	 	);
	 SetConsoleActiveScreenBuffer(hOutBuf);
	 CONSOLE_CURSOR_INFO cci;
	 cci.bVisible = 0;
	 cci.dwSize = 1;
	 SetConsoleCursorInfo(hOutput, &cci);
	 SetConsoleCursorInfo(hOutBuf, &cci);
	 DWORD bytes = 0;
	 char data[3200];

	srand(time(nullptr));
	while(true)
	{

		system("cls");
		g_sGameMgr.drawScene();
		 ReadConsoleOutputCharacterA(hOutput, data, 3200, coord, &bytes);
		 WriteConsoleOutputCharacterA(hOutBuf, data, 3200, coord, &bytes);
	}
	return 0;
}

//完善这个游戏，添加升级，玩家属性要增强，  经验/总经验，显示：等级，经验/总经验。 
//升级： 0/100    1000000   连续升级。
//敌人添加配置数据，经验数据。
//不同关卡，地数据：  每进入一关等级重置。   不同敌人：关卡1只有3种，关卡2 4种， 3  5种，地图数据配置敌人ID
//当前前关卡，有几波敌人，每一波敌人数量
//第一关： 第一波敌人，3001，3002   总共有10只，  第二波敌人，3002 3003  共20只  第三波敌人  全部  1000只。
//整Boss 打完 过关
//直接进入下一关。 等级重置，经验重置，   玩家里面应该配置个ID，当玩家出来的时候把ID接收，重置时候，再次通过ID获取玩家数据。
//道具： 打死敌人才有可能在敌人的位置出现道具。
//概率问题，每一种敌人，可以配置一个数值。 打死敌人再移除敌人之前要先拿到敌人中心的行列，再去移除敌人，这个时候调用道具管理者.add道具（坐标）；
//地图里面还要处理玩家跟道具碰撞。 实现相应效果， 加攻击力（永久，有时限） 加血（不要越加越多玩家还需要有个血量上限。），移除所有敌人，
//玩家血条。
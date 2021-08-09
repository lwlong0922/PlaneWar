// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <ctime>
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <Windows.h>
#include <WinUser.h>
#include <fstream>
#include <string>
#include "DataMgr.h"
#include "GameMgr.h"


using namespace std;

#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code) & 0x8000 ? 1 : 0)

enum
{
	E_MENU_START,
	E_MENU_SET,
	E_MENU_EXIT
};

enum
{
	E_GAME_MENU,
	E_GAME_MAP,
	E_GAME_SET,
	E_GAME_EXIT,
	E_GAME_TRANSITION
};

enum
{
	E_BULLET_PLAYER,
	E_BULLET_ENEMY
};


extern SDataMgr g_sDataMgr;
extern SGameMgr g_sGameMgr;



// TODO:  在此处引用程序需要的其他头文件

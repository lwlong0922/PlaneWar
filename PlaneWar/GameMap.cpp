#include "stdafx.h"
#include "GameMap.h"

SGameMap::SGameMap()
{
	initAllData();
}

void SGameMap::onUpdate()
{
	if(KEY_DOWN(VK_ESCAPE))
	{
		g_sGameMgr.nGameState = E_GAME_MENU;
	}
	if(KEY_DOWN(VK_SPACE))
	{
		nextMap();
	}

	sPlayer.onUpdate();


	sBulletMgr.onUpdate();
	checkCollision();

	sPropsMgr.onUpdate();
	sEnemyMgr.onUpdate();
	checkCollision();
	checkFailure();
	checkWin();

}

void SGameMap::onRender()
{
	cout << "\t" << curSMapData.strName << endl;
	for(int i = 0; i < curSMapData.nRowSize; i++)
	{
		for(int j = 0; j < curSMapData.nColSize; j++)
		{
			//■□●☆
			SEnemy sEnemy = sEnemyMgr.getEnemy(i, j);
			SBullet sBullet = sBulletMgr.getBullet(i, j);
			SProps sProps = sPropsMgr.getSProps(i, j);
			if(1 == curSMapData.arrMap[i][j])
			{
				cout << "■";
			}
			else if(sPlayer.isExist(i, j))
			{
				sPlayer.onRender();
			}
			else if(sEnemy.isExist(i, j))
			{
				//需要改为子弹自己渲染
				sEnemy.onRender();
			}
			else if(sBullet.isExist(i, j))
			{
				sBullet.onRender();
			}
			else if(sProps.isExist(i, j))
			{
				sProps.onRender();
			}
			else
			{
				cout << "  ";
			}
		}
		if(i == 0)
		{
			cout << "等级:\t" << sPlayer.nLevel;

		}
		if(i == 1)
		{
			cout << "飞机名称:" << sPlayer.sPlayerData.strName;
		}
		if(i == 2)
		{
			cout << "血量:\t" << sPlayer.sPlayerData.nHp << "/" << sPlayer.sPlayerData.nMaxHp;
		}
		if(i == 3)
		{
			cout << "蓝量:\t" << sPlayer.sPlayerData.nMp << "/" << sPlayer.sPlayerData.nMaxMp;
		}
		if(i == 4)
		{
			cout << "经验:\t" << sPlayer.nExp << "/" << sPlayer.nLevel * 100;
		}
		if(i == 5)
		{
			cout << "攻击力:\t" << sPlayer.sPlayerData.nAtk;
		}
		if(i == 6)
		{
			cout << "防御力:\t" << sPlayer.sPlayerData.nDef;
		}
		cout << endl;
	}
}

void SGameMap::checkCollision()
{
	vector<SEnemy>& vecEnemies = sEnemyMgr.vecEnemies;
	vector<SBullet>& vecBullets = sBulletMgr.vecBullets;
	vector<SProps>& vecProps = sPropsMgr.vecSProps;
	for(int i = 0; i < vecBullets.size(); i++)
	{
		//子弹和敌机
		if(vecBullets[i].nType == E_BULLET_PLAYER)
		{
			for(int j = 0; j < vecEnemies.size(); j++)
			{
				if(!vecBullets.empty())
				{
					if(j >= 0 && vecEnemies[j].isExist(vecBullets[i].position))
					{
						int nDamage = (vecBullets[i].bulletDamage - vecEnemies[j].sEnemyData.nDef) - 20 + rand() % 41;
						nDamage = nDamage>0 ? nDamage : 1;
						vecEnemies[j].damage(nDamage);
						vecBullets.erase(vecBullets.begin() + i--);
						break;
					}
				}
			}
		}
		else if(vecBullets[i].nType == E_BULLET_ENEMY)//子弹和玩家
		{
			if(sPlayer.isExist(vecBullets[i].position))
			{
				int nDamage = (vecBullets[i].bulletDamage - sPlayer.sPlayerData.nDef);
				nDamage = nDamage > 0 ? nDamage : 1;
				sPlayer.sPlayerData.nHp -= nDamage;
				vecBullets.erase(vecBullets.begin() + i--);
			}
		}
	}

	//玩家和敌机
	for(int i = 0; i < vecEnemies.size(); i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(sPlayer.isExist(vecEnemies[i].arrEnemy[j]))
			{
				int nDamage = (vecEnemies[i].sEnemyData.nHp - sPlayer.sPlayerData.nDef);
				nDamage = nDamage > 0 ? nDamage : 1;
				sPlayer.sPlayerData.nHp -= nDamage;
				nScore += 1;
				vecEnemies[i].sEnemyData.nHp = 0;
				break;
			}
		}
	}
	//玩家和道具
	for(int i = 0; i < vecProps.size(); i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(sPlayer.isExist(vecProps[i].sData))
			{
				sPlayer.propsToStrengthen(vecProps[i]);
				vecProps.erase(vecProps.begin() + i--);
				break;
			}
		}
	}
}

void SGameMap::checkFailure()
{
	if(sPlayer.sPlayerData.nHp <= 0)
	{
		initAllData();
		g_sGameMgr.nGameState = E_GAME_TRANSITION;
		g_sGameMgr.sGameTransition.nextState = E_GAME_MENU;
		g_sGameMgr.sGameTransition.str = "\n\t菜逼，就这？？？\n\n\t按回车返回吧\n\n";
	}
	if(sEnemyMgr.nCurBunch == curSMapData.vecBunch.size())
	{
		for(int i = 0; i < sEnemyMgr.vecEnemies.size(); i++)
		{
			if(sEnemyMgr.vecEnemies[i].arrEnemy[0].nRow == curSMapData.nRowSize - 1)
			{
				initAllData();
				g_sGameMgr.nGameState = E_GAME_TRANSITION;
				g_sGameMgr.sGameTransition.nextState = E_GAME_MENU;
				g_sGameMgr.sGameTransition.str = "\n\t菜逼，就这？？？\n\n\t按回车返回吧\n\n";
				break;
			}
		}
	}
}

void SGameMap::initAllData()
{
	nScore = 0;
	curSMapData = g_sDataMgr.sMapDataMgr.getDataById(g_sDataMgr.sMapDataMgr.vecSMapData[0].nId);
	sPlayer.setPosition(curSMapData.nInitRow, curSMapData.nInitRow);
	sPlayer.initDate(g_sDataMgr.sPlayerDataMgr.vecSPlayerData[0].nId);
	sBulletMgr.initData();
	sEnemyMgr.initData();
	sPropsMgr.init();
}


void SGameMap::checkWin()
{
	if(sEnemyMgr.nCurBunch == curSMapData.vecBunch.size())
	{
		if(sEnemyMgr.vecEnemies.size() == 0)
		{
			nextMap();
		}
	}
}

void SGameMap::nextMap()
{
	int i = 0;
	for(; i < g_sDataMgr.sMapDataMgr.vecSMapData.size(); i++)
	{
		if(curSMapData.nId == g_sDataMgr.sMapDataMgr.vecSMapData[i].nId)
		{
			break;
		}
	}
	if(i + 1 < g_sDataMgr.sMapDataMgr.vecSMapData.size())
	{
		curSMapData = g_sDataMgr.sMapDataMgr.getDataById(g_sDataMgr.sMapDataMgr.vecSMapData[i + 1].nId);
		sPlayer.setPosition(curSMapData.nInitRow, curSMapData.nInitRow);
		sPlayer.initDate(sPlayer.sPlayerData.nId);
		sBulletMgr.initData();
		sEnemyMgr.initData();
		sPropsMgr.init();
		g_sGameMgr.nGameState = E_GAME_TRANSITION;
		g_sGameMgr.sGameTransition.nextState = E_GAME_MAP;
		g_sGameMgr.sGameTransition.str = "\n\n\t按回车进入下一关\n\n";
	}
	else
	{
		initAllData();
		g_sGameMgr.nGameState = E_GAME_TRANSITION;
		g_sGameMgr.sGameTransition.nextState = E_GAME_MENU;
		g_sGameMgr.sGameTransition.str = "\n\t恭喜通关！！！\n\n\t按回车返回吧\n\n";
	}
}

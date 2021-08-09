#pragma once
#include "Player.h"
#include "BulletMgr.h"
#include "EnemyMgr.h"
#include "DataStruct.h"
#include "PropsMgr.h"

//��ͼ
struct SGameMap
{
	SGameMap();

	//���ݸ��£�������ң��ӵ����������ݸ��£���ײ�ж�
	void onUpdate();
	//��Ⱦ��������
	void onRender();
	//�����ײ
	void checkCollision();
	//���ʧ��
	void checkFailure();
	//��ʼ������
	void initAllData();

	void checkWin();
	void nextMap();
	int nScore;

	SPlayer sPlayer;
	SBulletMgr sBulletMgr;
	SEnemyMgr sEnemyMgr;
	SPropsMgr sPropsMgr;

	SMapData curSMapData;
};


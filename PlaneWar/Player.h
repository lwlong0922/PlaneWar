#pragma once
#include "DataStruct.h"

struct SProps;

//���
struct SPlayer
{
	SPlayer();
	//���ݸ��£���������ƶ��ͷ����ӵ�
	void onUpdate();
	//��Ⱦ���
	void onRender() const;
	//��������
	void onBackUp();
	//��ԭ����
	void onRestore();
	void releaseSkills();
	//����λ��
	void setPosition(const int& nInRow, const int& nInCol);
	//�жϵ����Ƿ����
	bool isExist(const int& nInRow, const int& nInCol) const;
	//�жϵ����Ƿ����
	bool isExist(const SData& sInData) const;
	//��ʼ������
	void initDate(int nInId);
	//����ǿ��
	void propsToStrengthen(const SProps& sProps);

	SPlayerData sPlayerData;

	int nFireInterval;
	int nFireTime;
	int nExp;
	int nLevel;
	bool bIsFire;
	SData arrPlayer[4];
};

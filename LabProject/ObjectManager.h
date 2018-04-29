#pragma once
#include "GameObject.h"
class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	

private:
	int											m_nObjects = 0;
	std::list<std::shared_ptr<CGameObject>>		m_plObjects;
	std::list<std::shared_ptr<CBullet>>			m_plBullets;
	std::list<std::shared_ptr<CEnermy>>			m_plEnermys;
	std::list<std::shared_ptr<CBonusObject>>	m_plBonusObjects;


public:
	//������Ʈ�� �����ϴ� �Լ�
	void newpBullet(CBullet * pBullet);
	void newEnermy(CEnermy * pEnermy);
	void newBonusObject(CBonusObject * pBonusObject);


	//������Ʈ�� �Ҹ��ϴ� �Լ�
	void deleteBullet(CBullet * pBullet);
	void deleteEnermy(CEnermy * pEnermy);
	void deleteBounusObject(CBonusObject * BonusObject);



	//����Ʈ�� �ҷ����� �Լ�
	const std::list<std::shared_ptr<CGameObject>> GetGameObjectList();
	const std::list<std::shared_ptr<CBullet>> GetpBulletList();
	const std::list<std::shared_ptr<CEnermy>> GetpEnermytList();
	const std::list<std::shared_ptr<CBonusObject>> GetpBonusObjectList();




};


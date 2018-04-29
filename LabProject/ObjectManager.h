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
	//오브젝트를 생성하는 함수
	void newpBullet(CBullet * pBullet);
	void newEnermy(CEnermy * pEnermy);
	void newBonusObject(CBonusObject * pBonusObject);


	//오브젝트를 소멸하는 함수
	void deleteBullet(CBullet * pBullet);
	void deleteEnermy(CEnermy * pEnermy);
	void deleteBounusObject(CBonusObject * BonusObject);



	//리스트를 불러오는 함수
	const std::list<std::shared_ptr<CGameObject>> GetGameObjectList();
	const std::list<std::shared_ptr<CBullet>> GetpBulletList();
	const std::list<std::shared_ptr<CEnermy>> GetpEnermytList();
	const std::list<std::shared_ptr<CBonusObject>> GetpBonusObjectList();




};


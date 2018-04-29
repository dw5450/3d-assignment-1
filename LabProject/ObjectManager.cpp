#include "stdafx.h"
#include "ObjectManager.h"


ObjectManager::ObjectManager()
{
}

void ObjectManager::newpBullet(CBullet * pBullet)
{
	m_plObjects.emplace_back(pBullet);
	m_plBullets.emplace_back(pBullet);
}

void ObjectManager::newEnermy(CEnermy * pEnermy)
{
	m_plObjects.emplace_back(pEnermy);
	m_plEnermys.emplace_back(pEnermy);
}

void ObjectManager::newBonusObject(CBonusObject * pBonusObject)
{
	m_plObjects.emplace_back(pBonusObject);
	m_plBonusObjects.emplace_back(pBonusObject);

}



void ObjectManager::deleteBullet(CBullet * pBullet)
{
	m_plObjects.e
	m_plBullets.emplace_back(pBullet);
}

void ObjectManager::newEnermy(CEnermy * pEnermy)
{
	m_plObjects.emplace_back(pEnermy);
	m_plEnermys.emplace_back(pEnermy);
}

void ObjectManager::newBonusObject(CBonusObject * pBonusObject)
{
	m_plObjects.emplace_back(pBonusObject);
	m_plBonusObjects.emplace_back(pBonusObject);

}
#pragma once

#include "GameObject.h"
#include "Player.h"

class CScene
{
public:	//���� �Ҹ���
	CScene();
	virtual ~CScene();
	virtual void BuildObjects();
	virtual void ReleaseObjects();

	CPlayer										*m_pPlayer = NULL;

	float										m_iObjectResponTime = 0;


	CWallsObject				*m_pWallsObject = NULL;

public: //�ൿ �Լ�
	virtual void CheckObjectByObjectCollisions();
	virtual void CheckObjectByWallCollisions();
	virtual void CheckPlayerByWallCollisions();
	virtual void CheckObjectByBulletCollisions();

	virtual void Animate(float fElapsedTime);
	virtual void Render(HDC hDCFrameBuffer, CCamera *pCamera);
	void ResponEnemy(float fElapsedTime);

	virtual void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	virtual void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);


};


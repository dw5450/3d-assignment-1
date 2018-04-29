#pragma once

#include "GameObject.h"
#include "Player.h"

class CScene
{
public:	//생성 소멸자
	CScene();
	virtual ~CScene();
	virtual void BuildObjects();
	virtual void ReleaseObjects();

	CPlayer										*m_pPlayer = NULL;

	float										m_iObjectResponTime = 0;


	CWallsObject				*m_pWallsObject = NULL;

public: //행동 함수
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


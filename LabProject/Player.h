#pragma once

#include "GameObject.h"

<<<<<<< HEAD
=======
class CBullet : public CGameObject
{
public:
	CBullet();
	virtual ~CBullet();

public:
	float	fElapseTime = 0.0f;								//경과 시간.

};
>>>>>>> e4d70fa0deb8f466847733712755fec877793736


class CPlayer : public CGameObject
{
public:	//생성 소멸자
	CPlayer();
	virtual ~CPlayer();

	XMFLOAT3					m_xmf3Position;
	XMFLOAT3					m_xmf3Right;
	XMFLOAT3					m_xmf3Up;
	XMFLOAT3					m_xmf3Look;

	XMFLOAT3					m_xmf3CameraOffset;
	float						m_fFriction = 125.0f;

	float           			m_fPitch = 0.0f;
	float           			m_fYaw = 0.0f;
	float           			m_fRoll = 0.0f;

	CCamera						*m_pCamera = NULL;

	UINT						m_iMax_Bullet_num = MAXBULLETNUM;
	UINT						m_iCur_Bullet_num = MAXBULLETNUM;
	bool						m_bReload = false;

public: //설정
	void SetPosition(float x, float y, float z);
	void SetPosition(XMFLOAT3 &xmf);
	void SetCameraOffset(XMFLOAT3& xmf3CameraOffset);

public://행동
	void Move(DWORD dwDirection, float fDistance);						//이동
	void Move(XMFLOAT3& xmf3Shift);				//이동
	void Move(float x, float y, float z);								//이동
	void Rotate(float fPitch = 0.0f, float fYaw = 0.0f, float fRoll = 0.0f);	//회전
	void Update(float fTimeElapsed=0.016f);								//업데이트
	void ShotBullet(float fTimeElapsed);								//총을 쏘다
	virtual void Animate(float fElapsedTime);
	virtual void Render(HDC hDCFrameBuffer, CCamera *pCamera);			//화면에 그림
};


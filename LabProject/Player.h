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
	float	fElapseTime = 0.0f;								//��� �ð�.

};
>>>>>>> e4d70fa0deb8f466847733712755fec877793736


class CPlayer : public CGameObject
{
public:	//���� �Ҹ���
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

public: //����
	void SetPosition(float x, float y, float z);
	void SetPosition(XMFLOAT3 &xmf);
	void SetCameraOffset(XMFLOAT3& xmf3CameraOffset);

public://�ൿ
	void Move(DWORD dwDirection, float fDistance);						//�̵�
	void Move(XMFLOAT3& xmf3Shift);				//�̵�
	void Move(float x, float y, float z);								//�̵�
	void Rotate(float fPitch = 0.0f, float fYaw = 0.0f, float fRoll = 0.0f);	//ȸ��
	void Update(float fTimeElapsed=0.016f);								//������Ʈ
	void ShotBullet(float fTimeElapsed);								//���� ���
	virtual void Animate(float fElapsedTime);
	virtual void Render(HDC hDCFrameBuffer, CCamera *pCamera);			//ȭ�鿡 �׸�
};


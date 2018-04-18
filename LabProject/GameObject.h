#pragma once

#include "Mesh.h"
#include "Camera.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
class CGameObject
{
public:
	//���� �Ҹ���
	CGameObject();
	CGameObject(CMesh *pMesh);
	virtual ~CGameObject();

public:
	bool						m_bActive = true;								//�����ϴ°�?
	
	CMesh						*m_pMesh = NULL;
    XMFLOAT4X4					m_xmf4x4World;    

	BoundingOrientedBox			m_xmOOBB;
	
	CGameObject					*m_pObjectCollided = NULL;

	DWORD						m_dwColor;

	XMFLOAT3					m_xmf3MovingDirection;
	float						m_fMovingSpeed;
	float						m_fMovingRange;

	XMFLOAT3					m_xmf3RotationAxis;
	float						m_fRotationSpeed;

public:// ���� �Լ�
	//�Ž� ����
	void SetMesh(CMesh *pMesh) { m_pMesh = pMesh; if (pMesh) pMesh->AddRef(); }
	void SetColor(DWORD dwColor) { m_dwColor = dwColor; }
	
	//��ġ ����
	void SetPosition(float x, float y, float z);
	void SetPosition(XMFLOAT3& xmf3Position);

	//�̵� ����
	void SetMovingDirection(XMFLOAT3& xmf3MovingDirection) { m_xmf3MovingDirection = Vector3::Normalize(xmf3MovingDirection); }
	void SetMovingSpeed(float fSpeed) { m_fMovingSpeed = fSpeed; }
	void SetMovingRange(float fRange) { m_fMovingRange = fRange; }

	//ȸ�� ����
	void SetRotationAxis(XMFLOAT3& xmf3RotationAxis) { m_xmf3RotationAxis = Vector3::Normalize(xmf3RotationAxis); }
	void SetRotationSpeed(float fSpeed) { m_fRotationSpeed = fSpeed; }

public: //���� �Լ�
	XMFLOAT3 GetPosition() const;
	XMFLOAT3 GetLook() const ;
	XMFLOAT3 GetUp() const ;
	XMFLOAT3 GetRight() const;

public: // �ൿ �Լ�
	//�̵�
	void MoveStrafe(float fDistance=1.0f);		//x�� �̵�
	void MoveUp(float fDistance=1.0f);			//y�� �̵�
	void MoveForward(float fDistance=1.0f);		//z�� �̵�
	void Move(XMFLOAT3& vDirection, float fSpeed);	//���� ���ͷ� �̵�
	//ȸ��
	void Rotate(float fPitch=10.0f, float fYaw=10.0f, float fRoll=10.0f);
	void Rotate(XMFLOAT3& xmf3Axis, float fAngle);
	//�ִϸ��̼�
	virtual void Animate(float fElapsedTime);
	//������
	virtual void Render(HDC hDCFrameBuffer, CCamera *pCamera);
};


class CExplosiveObject : public CGameObject
{
public://���� ����/�Լ�
	static CMesh				*m_pExplosionMesh;						//���� �Ž�
	static XMFLOAT3				m_pxmf3SphereVectors[EXPLOSION_DEBRISES]; //���� ����
	static void PrepareExplosion();										//���� ���� �Լ�

public:
	//����, �Ҹ���
	CExplosiveObject();
	virtual ~CExplosiveObject();

	bool						m_bBlowingUp = false;		//���� ����

	XMFLOAT4X4					m_pxmf4x4Transforms[EXPLOSION_DEBRISES];	//���� ����

	float						m_fElapsedTimes = 0.0f;//���� ����ð�
	float						m_fDuration = 1.0f;		//���� �ð�
	float						m_fExplosionSpeed = 10.0f;	//������ ������ �ӵ�
	float						m_fExplosionRotation = 720.0f;	//������ ȸ����

public://�ൿ �Լ�
	virtual void Animate(float fElapsedTime); //*�� �� * 
	virtual void Render(HDC hDCFrameBuffer, CCamera *pCamera);

};



class CWallsObject : public CGameObject
{
public:
	CWallsObject();
	virtual ~CWallsObject();

public:
	XMFLOAT4					m_pxmf4WallPlanes[6];				//�鼳��
};

#pragma once

#include "Mesh.h"
#include "Camera.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
class CGameObject
{
public:
	//생성 소멸자
	CGameObject();
	CGameObject(CMesh *pMesh);
	virtual ~CGameObject();

public:
	bool						m_bActive = true;								//실행하는가?
	
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

public:// 설정 함수
	//매쉬 설정
	void SetMesh(CMesh *pMesh) { m_pMesh = pMesh; if (pMesh) pMesh->AddRef(); }
	void SetColor(DWORD dwColor) { m_dwColor = dwColor; }
	
	//위치 설정
	void SetPosition(float x, float y, float z);
	void SetPosition(XMFLOAT3& xmf3Position);

	//이동 설정
	void SetMovingDirection(XMFLOAT3& xmf3MovingDirection) { m_xmf3MovingDirection = Vector3::Normalize(xmf3MovingDirection); }
	void SetMovingSpeed(float fSpeed) { m_fMovingSpeed = fSpeed; }
	void SetMovingRange(float fRange) { m_fMovingRange = fRange; }

	//회전 설정
	void SetRotationAxis(XMFLOAT3& xmf3RotationAxis) { m_xmf3RotationAxis = Vector3::Normalize(xmf3RotationAxis); }
	void SetRotationSpeed(float fSpeed) { m_fRotationSpeed = fSpeed; }

public: //참조 함수
	XMFLOAT3 GetPosition() const;
	XMFLOAT3 GetLook() const ;
	XMFLOAT3 GetUp() const ;
	XMFLOAT3 GetRight() const;

public: // 행동 함수
	//이동
	void MoveStrafe(float fDistance=1.0f);		//x축 이동
	void MoveUp(float fDistance=1.0f);			//y축 이동
	void MoveForward(float fDistance=1.0f);		//z축 이동
	void Move(XMFLOAT3& vDirection, float fSpeed);	//방향 벡터로 이동
	//회전
	void Rotate(float fPitch=10.0f, float fYaw=10.0f, float fRoll=10.0f);
	void Rotate(XMFLOAT3& xmf3Axis, float fAngle);
	//애니메이션
	virtual void Animate(float fElapsedTime);
	//랜더링
	virtual void Render(HDC hDCFrameBuffer, CCamera *pCamera);
};


class CExplosiveObject : public CGameObject
{
public://전역 변수/함수
	static CMesh				*m_pExplosionMesh;						//폭발 매쉬
	static XMFLOAT3				m_pxmf3SphereVectors[EXPLOSION_DEBRISES]; //폭발 방향
	static void PrepareExplosion();										//폭발 설정 함수

public:
	//생성, 소멸자
	CExplosiveObject();
	virtual ~CExplosiveObject();

	bool						m_bBlowingUp = false;		//폭발 여부

	XMFLOAT4X4					m_pxmf4x4Transforms[EXPLOSION_DEBRISES];	//폭발 방향

	float						m_fElapsedTimes = 0.0f;//폭발 경과시간
	float						m_fDuration = 1.0f;		//폭발 시간
	float						m_fExplosionSpeed = 10.0f;	//폭발이 나가는 속도
	float						m_fExplosionRotation = 720.0f;	//폭발의 회전각

public://행동 함수
	virtual void Animate(float fElapsedTime); //*폭 발 * 
	virtual void Render(HDC hDCFrameBuffer, CCamera *pCamera);

};



class CWallsObject : public CGameObject
{
public:
	CWallsObject();
	virtual ~CWallsObject();

public:
	XMFLOAT4					m_pxmf4WallPlanes[6];				//면설정
};

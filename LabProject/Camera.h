#pragma once


//화면 크기
struct VIEWPORT
{
	int							m_xStart;
	int							m_yStart;
	int							m_nWidth;
	int							m_nHeight;
};

class CPlayer;

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
class CCamera
{
public:
	CCamera();
	virtual ~CCamera();

	XMFLOAT3					m_xmf3Position;
	XMFLOAT3					m_xmf3Right;
	XMFLOAT3					m_xmf3Up;
	XMFLOAT3					m_xmf3Look;

	XMFLOAT4X4					m_xmf4x4View;					//카메라 행렬
	XMFLOAT4X4					m_xmf4x4Projection;				//투영 변환 행렬
	XMFLOAT4X4					m_xmf4x4ViewProject;			//카메라 변환 행렬		(카메라 행렬의 역행렬)

	VIEWPORT					m_Viewport;

public:	//카메라 설정

	//변환 행렬 설정
	void GenerateViewMatrix();							//카메라 변환
	void GenerateProjectionMatrix(float fNearPlaneDistance, float fFarPlaneDistance, float fFOVAngle);
	void SetViewport(int xStart, int yStart, int nWidth, int nHeight);
	
	//바라보는 방향 설정
	void SetLookAt(XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up);
	void SetLookAt(XMFLOAT3& vPosition, XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up);
	
	//좌표값 변경 설정
	void Move(XMFLOAT3& xmf3Shift);
	void Move(float x, float y, float z);
	void Rotate(float fPitch = 0.0f, float fYaw = 0.0f, float fRoll = 0.0f);
	void Update(CPlayer *pPlayer, XMFLOAT3& xmf3LookAt, float fTimeElapsed = 0.016f);
};



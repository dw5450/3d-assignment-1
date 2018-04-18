#include "stdafx.h"
#include "Player.h"

////////////////////////////////////////////////////////////////////////////////////
CBullet::CBullet()
{

}

CBullet::~CBullet()
{

}
/////////////////////////////////////////////////////////////////////////////////////////////////////
//생성 소멸

CPlayer::CPlayer()
{
	//카메라 설정
	m_pCamera = new CCamera();
	m_pCamera->GenerateProjectionMatrix(1.01f, 5000.0f, 60.0f);
	m_pCamera->SetViewport(0, 0, CLIENT_WIDTH, CLIENT_HEIGHT);

	//플레이어 포지션 설정
	SetPosition(0, 0, 0);
	m_xmf3Right = XMFLOAT3(1.0f, 0.0f, 0.0f);
	m_xmf3Up = XMFLOAT3(0.0f, 1.0f, 0.0f);
	m_xmf3Look = XMFLOAT3(0.0f, 0.0f, 1.0f);

	m_xmf3CameraOffset = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//총알 설정
	CCubeMesh *pObjectCubeMesh = new CCubeMesh(1.0f, 1.0f, 1.0f);
	for (int i = 0; i < MAXBULLETNUM; i++) {
		m_pBullets[i] = new CBullet();
		m_pBullets[i]->m_bActive = false;
		m_pBullets[i]->SetPosition(-1000.0f, -1000.0f, -1000.0f);
		m_pBullets[i]->SetMesh(pObjectCubeMesh);
		m_pBullets[i]->SetColor(RGB(255, 0, 0));
		m_pBullets[i]->SetMovingSpeed(BULLETSPEED);
		m_pBullets[i]->SetRotationSpeed(600.0f);
	}
}

CPlayer::~CPlayer()
{
	if (m_pCamera) delete m_pCamera;

	if (m_pBullets) {
		for (int i = 0; i < BULLET_NUM; i++)
			delete m_pBullets[i];
	}

}
//설정
// 포지션 설정.
void CPlayer::SetPosition(float x, float y, float z)
{
	m_xmf3Position = XMFLOAT3(x, y, z);

	CGameObject::SetPosition(x, y, z);
}

void CPlayer::SetPosition(XMFLOAT3 &xmf)
{
	m_xmf3Position = xmf;

	CGameObject::SetPosition(xmf);
}

void CPlayer::SetCameraOffset(XMFLOAT3& xmf3CameraOffset)
{
	m_xmf3CameraOffset = xmf3CameraOffset;
	m_pCamera->SetLookAt(Vector3::Add(m_xmf3Position, m_xmf3CameraOffset), m_xmf3Position, m_xmf3Up);
	m_pCamera->GenerateViewMatrix();
}

//행동
void CPlayer::Move(DWORD dwDirection, float elapse_time)
{
	float fDistance = m_fMovingSpeed * elapse_time;
	if (dwDirection)
	{
		if (dwDirection & DIR_FORWARD) SetMovingDirection(m_xmf3Look);
		if (dwDirection & DIR_BACKWARD) SetMovingDirection(Vector3::ScalarProduct(m_xmf3Look, -1));
		if (dwDirection & DIR_RIGHT) SetMovingDirection(m_xmf3Right);
		if (dwDirection & DIR_LEFT) SetMovingDirection(Vector3::ScalarProduct(m_xmf3Right, -1));
		if (dwDirection & DIR_UP) SetMovingDirection(m_xmf3Up);
		if (dwDirection & DIR_DOWN) SetMovingDirection(Vector3::ScalarProduct(m_xmf3Up, -1));
	}
	//else
		//SetMovingDirection(XMFLOAT3(0.0f, 0.0f, 0.0f));

}

void CPlayer::Move(XMFLOAT3& xmf3Shift)
{
	SetPosition(Vector3::Add(xmf3Shift, m_xmf3Position));
	m_pCamera->Move(xmf3Shift);
}

void CPlayer::Move(float x, float y, float z)
{
	Move(XMFLOAT3(x, y, z));
}

void CPlayer::Rotate(float fPitch, float fYaw, float fRoll)
{
	m_pCamera->Rotate(fPitch, fYaw, fRoll);
	if (fPitch != 0.0f)
	{
		XMMATRIX mtxRotate = XMMatrixRotationAxis(XMLoadFloat3(&m_xmf3Right), XMConvertToRadians(fPitch));
		m_xmf3Look = Vector3::TransformNormal(m_xmf3Look, mtxRotate);
		m_xmf3Up = Vector3::TransformNormal(m_xmf3Up, mtxRotate);
	}
	if (fYaw != 0.0f)
	{
		XMMATRIX mtxRotate = XMMatrixRotationAxis(XMLoadFloat3(&m_xmf3Up), XMConvertToRadians(fYaw));
		m_xmf3Look = Vector3::TransformNormal(m_xmf3Look, mtxRotate);
		m_xmf3Right = Vector3::TransformNormal(m_xmf3Right, mtxRotate);
	}
	if (fRoll != 0.0f)
	{
		XMMATRIX mtxRotate = XMMatrixRotationAxis(XMLoadFloat3(&m_xmf3Look), XMConvertToRadians(fRoll));
		m_xmf3Up = Vector3::TransformNormal(m_xmf3Up, mtxRotate);
		m_xmf3Right = Vector3::TransformNormal(m_xmf3Right, mtxRotate);
	}

	m_xmf3Look = Vector3::Normalize(m_xmf3Look);
	m_xmf3Right = Vector3::Normalize(Vector3::CrossProduct(m_xmf3Up, m_xmf3Look));
	m_xmf3Up = Vector3::Normalize(Vector3::CrossProduct(m_xmf3Look, m_xmf3Right));
}

void CPlayer::Update(float fTimeElapsed)
{
	m_pCamera->Update(this, m_xmf3Position, fTimeElapsed);
	m_pCamera->GenerateViewMatrix();

}

void CPlayer::ShotBullet(float fTimeElapsed)
{
	//총알을 발사할 경우
	if (m_bShotedBullet) {
		m_bShotedBullet = false;
		for (int i = 0; i < MAXBULLETNUM; i++) {
			if (m_pBullets[i]->m_bActive == false && m_fBulletCoolTime < 0) {
				m_pBullets[i]->m_bActive = true;
				m_pBullets[i]->SetPosition(m_xmf3Position);
				m_pBullets[i]->SetMovingDirection(m_xmf3Look);
				m_pBullets[i]->SetRotationAxis(m_xmf3Look);
				m_fBulletCoolTime = BULLETCOOLTIME;
				break;
			}
		}
	}
	for (int i = 0; i < MAXBULLETNUM; i++)
	{
		if (m_pBullets[i]->m_bActive) {
			if (m_pBullets[i]->fElapseTime > BULLETLIMITTIME) {
				m_pBullets[i]->m_bActive = false;
				m_pBullets[i]->fElapseTime = 0;
			}
			else {
				m_pBullets[i]->fElapseTime += fTimeElapsed;
			}
		}
	}
	m_fBulletCoolTime -= fTimeElapsed;
}

void CPlayer::Animate(float fElapsedTime)
{
	if (fElapsedTime > 0.0f)
		SetPosition(XMFLOAT3(10, 10, 10));

	ShotBullet(fElapsedTime);

	for (int i = 0; i < BULLET_NUM; i++)
		m_pBullets[i]->Animate(fElapsedTime);
}



void CPlayer::Render(HDC hDCFrameBuffer, CCamera *pCamera)
{
	m_xmf4x4World._11 = m_xmf3Right.x; m_xmf4x4World._12 = m_xmf3Right.y; m_xmf4x4World._13 = m_xmf3Right.z;
	m_xmf4x4World._21 = m_xmf3Up.x; m_xmf4x4World._22 = m_xmf3Up.y; m_xmf4x4World._23 = m_xmf3Up.z;
	m_xmf4x4World._31 = m_xmf3Look.x; m_xmf4x4World._32 = m_xmf3Look.y; m_xmf4x4World._33 = m_xmf3Look.z;
	m_xmf4x4World._41 = m_xmf3Position.x; m_xmf4x4World._42 = m_xmf3Position.y; m_xmf4x4World._43 = m_xmf3Position.z;

	m_xmf4x4World = Matrix4x4::Multiply(XMMatrixRotationRollPitchYaw(XMConvertToRadians(90.0f), 0.0f, 0.0f), m_xmf4x4World);
	
	CGameObject::Render(hDCFrameBuffer,pCamera);
	
	for (int i = 0; i < MAXBULLETNUM; i++) {
		m_pBullets[i]->Render(hDCFrameBuffer, pCamera);
	}
}


////////////////////////////////////////////////////////////////////////////////////////////


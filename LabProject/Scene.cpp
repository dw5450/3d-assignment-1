#include "stdafx.h"
#include "Scene.h"
//����� �׸��ϴ�
//������Ʈ���� ����, ��ġ ��ŵ�ϴ�.
//�浹üũ�� �����մϴ�.

CScene::CScene()
{

}

CScene::~CScene()
{
}

void CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}

void CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}

//������Ʈ���� �����մϴ�.
void CScene::BuildObjects()
{
	CExplosiveObject::PrepareExplosion();

	//������
	float fHalfWidth = 45.0f, fHalfHeight = 45.0f, fHalfDepth = 500.0f;									//1.0f �� 1m
	CWallMesh *pWallCubeMesh = new CWallMesh(fHalfWidth * 2.0f, fHalfHeight * 2.0f, fHalfDepth * 2.0f, 20);
	pWallCubeMesh->SetOOBB(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(fHalfWidth, fHalfHeight, fHalfDepth * 0.1f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));

	m_pWallsObject = new CWallsObject();
	m_pWallsObject->SetPosition(0.0f, 0.0f, 0.0f);
	m_pWallsObject->SetMesh(pWallCubeMesh);
	m_pWallsObject->SetColor(RGB(0, 0, 0));
	m_pWallsObject->m_pxmf4WallPlanes[0] = XMFLOAT4(+1.0f, 0.0f, 0.0f, fHalfWidth);
	m_pWallsObject->m_pxmf4WallPlanes[1] = XMFLOAT4(-1.0f, 0.0f, 0.0f, fHalfWidth);
	m_pWallsObject->m_pxmf4WallPlanes[2] = XMFLOAT4(0.0f, +1.0f, 0.0f, fHalfHeight);
	m_pWallsObject->m_pxmf4WallPlanes[3] = XMFLOAT4(0.0f, -1.0f, 0.0f, fHalfHeight);
	m_pWallsObject->m_pxmf4WallPlanes[4] = XMFLOAT4(0.0f, 0.0f, +1.0f, 10);
	m_pWallsObject->m_pxmf4WallPlanes[5] = XMFLOAT4(0.0f, 0.0f, -1.0f, 10);


	//ť�� ����
	CCubeMesh *pObjectCubeMesh = new CCubeMesh(4.0f, 4.0f, 4.0f);
	pObjectCubeMesh->SetOOBB(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(2.0f, 2.0f, 2.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));

	
	
}

//������Ʈ ���� �����մϴ�.
void CScene::ReleaseObjects()
{



}

//�浹�� üũ�մϴ�.
void CScene::CheckObjectByObjectCollisions()
{
	
}

void CScene::CheckObjectByWallCollisions()
{
	
}

void CScene::CheckPlayerByWallCollisions()
{
	
}

void CScene::CheckObjectByBulletCollisions()
{
	
}


void CScene::Animate(float fElapsedTime)
{


	m_pWallsObject->Animate(fElapsedTime);
	m_pPlayer->Animate(fElapsedTime);


	//���� �浹�Ͻ�
	CheckObjectByWallCollisions();
	CheckPlayerByWallCollisions();

	//������Ʈ���� �浹�ҽ�
	CheckObjectByObjectCollisions();

	//�Ѿ˰� �浹�ҽ�
	CheckObjectByBulletCollisions();

	ResponEnemy(fElapsedTime);
}

void CScene::Render(HDC hDCFrameBuffer, CCamera *pCamera)
{
	
}

void CScene::ResponEnemy(float fElapsedTime)
{
	
}


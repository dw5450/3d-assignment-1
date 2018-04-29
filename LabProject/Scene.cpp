#include "stdafx.h"
#include "Scene.h"
//장면을 그립니다
//오브젝트들을 생성, 위치 시킵니다.
//충돌체크를 실행합니다.

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

//오브젝트들을 생성합니다.
void CScene::BuildObjects()
{
	CExplosiveObject::PrepareExplosion();

	//벽설정
	float fHalfWidth = 45.0f, fHalfHeight = 45.0f, fHalfDepth = 500.0f;									//1.0f 당 1m
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


	//큐브 설정
	CCubeMesh *pObjectCubeMesh = new CCubeMesh(4.0f, 4.0f, 4.0f);
	pObjectCubeMesh->SetOOBB(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(2.0f, 2.0f, 2.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));

	
	
}

//오브젝트 들을 삭제합니다.
void CScene::ReleaseObjects()
{



}

//충돌을 체크합니다.
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


	//벽과 충돌하시
	CheckObjectByWallCollisions();
	CheckPlayerByWallCollisions();

	//오브젝트끼리 충돌할시
	CheckObjectByObjectCollisions();

	//총알과 충돌할시
	CheckObjectByBulletCollisions();

	ResponEnemy(fElapsedTime);
}

void CScene::Render(HDC hDCFrameBuffer, CCamera *pCamera)
{
	
}

void CScene::ResponEnemy(float fElapsedTime)
{
	
}


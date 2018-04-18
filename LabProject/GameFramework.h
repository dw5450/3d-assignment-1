#pragma once

//-----------------------------------------------------------------------------
// File: GameFramework.h
//오브젝트들을 생성 관리합니다.
//게임의 입력을 받고 그려줍니다.
//-----------------------------------------------------------------------------

#include "Timer.h"
#include "Scene.h"
#include "Player.h"

class CGameFramework
{
private:
	HINSTANCE					m_hInstance = NULL;
	HWND						m_hWnd = NULL;

	bool						m_bActive = true;						


	CGameTimer					m_GameTimer;							//시간

	HDC							m_hDCFrameBuffer = NULL;				//
	HBITMAP						m_hBitmapFrameBuffer = NULL;

	CPlayer						*m_pPlayer = NULL;						//플레이어 설정

	CScene						*m_pScene = NULL;						//프레임마다 그려지는 화면에서의 변화를 설정

public:			//생성 소멸
	CGameFramework();			//디폴트 생성자
	~CGameFramework();			//디폴트 소멸자
	bool OnCreate(HINSTANCE hInstance, HWND hMainWnd);				//프로그램을 생성
	void OnDestroy();												//프로그램을 제거										
	void BuildObjects();											//오브젝트들 생성
	void ReleaseObjects();											//오브젝트들 제거

public:			 //랜더링
	void BuildFrameBuffer();			//버퍼를 생성함
	void ClearFrameBuffer(DWORD dwColor);	//버퍼를 한가지 색으로 지움
	void PresentFrameBuffer();				//버퍼에 그림

public:			// 입력.
	void SetActive(bool bActive) { m_bActive = bActive; }					//실행 할지 않 할지 설정
	void ProcessInput();							//프로그램 입력 처리
	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);		//마우스의 입력 
	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);		//키보드의 입력 
	LRESULT CALLBACK OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);	//윈도우의 입력

	POINT						m_ptOldCursorPos;						//옜날 마우스의 좌표		

	_TCHAR						m_pszFrameRate[50];

public:			//변경점 적용
	void FrameAdvance();		//프레임마다 변경점을 적용


};


#pragma once

//-----------------------------------------------------------------------------
// File: GameFramework.h
//-----------------------------------------------------------------------------

#include "Timer.h"
#include "Scene.h"
#include "Player.h"

class CGameFramework
{
public:
	//생성 소멸
	CGameFramework();
	~CGameFramework();

	bool OnCreate(HINSTANCE hInstance, HWND hMainWnd);
	void OnDestroy();

	void BuildObjects();
	void ReleaseObjects();
	

	void SetActive(bool bActive) { m_bActive = bActive; }

private:
	HINSTANCE					m_hInstance = NULL;
	HWND						m_hWnd = NULL;

<<<<<<< HEAD
	bool						m_bActive = true;
=======
	bool						m_bActive = true;					//어디에 쓰이는지 모르겟음
	void SetActive(bool bActive) { m_bActive = bActive; }
>>>>>>> e4d70fa0deb8f466847733712755fec877793736

	CGameTimer					m_GameTimer;

	HDC							m_hDCFrameBuffer = NULL;
	HBITMAP						m_hBitmapFrameBuffer = NULL;

	CPlayer						*m_pPlayer = NULL;

	CScene						*m_pScene = NULL;

public:
	void BuildFrameBuffer();
	void ClearFrameBuffer(DWORD dwColor);
	void PresentFrameBuffer();

	void ProcessInput();

<<<<<<< HEAD
	void FrameAdvance();
=======
public:			// 입력.
	void ProcessInput();							//프로그램 입력 처리
	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);		//마우스의 입력 
	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);		//키보드의 입력 
	LRESULT CALLBACK OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);	//윈도우의 입력
>>>>>>> e4d70fa0deb8f466847733712755fec877793736

	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	POINT						m_ptOldCursorPos;

	_TCHAR						m_pszFrameRate[50];
};


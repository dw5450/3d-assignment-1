#pragma once

//-----------------------------------------------------------------------------
// File: GameFramework.h
//������Ʈ���� ���� �����մϴ�.
//������ �Է��� �ް� �׷��ݴϴ�.
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


	CGameTimer					m_GameTimer;							//�ð�

	HDC							m_hDCFrameBuffer = NULL;				//
	HBITMAP						m_hBitmapFrameBuffer = NULL;

	CPlayer						*m_pPlayer = NULL;						//�÷��̾� ����

	CScene						*m_pScene = NULL;						//�����Ӹ��� �׷����� ȭ�鿡���� ��ȭ�� ����

public:			//���� �Ҹ�
	CGameFramework();			//����Ʈ ������
	~CGameFramework();			//����Ʈ �Ҹ���
	bool OnCreate(HINSTANCE hInstance, HWND hMainWnd);				//���α׷��� ����
	void OnDestroy();												//���α׷��� ����										
	void BuildObjects();											//������Ʈ�� ����
	void ReleaseObjects();											//������Ʈ�� ����

public:			 //������
	void BuildFrameBuffer();			//���۸� ������
	void ClearFrameBuffer(DWORD dwColor);	//���۸� �Ѱ��� ������ ����
	void PresentFrameBuffer();				//���ۿ� �׸�

public:			// �Է�.
	void SetActive(bool bActive) { m_bActive = bActive; }					//���� ���� �� ���� ����
	void ProcessInput();							//���α׷� �Է� ó��
	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);		//���콺�� �Է� 
	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);		//Ű������ �Է� 
	LRESULT CALLBACK OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);	//�������� �Է�

	POINT						m_ptOldCursorPos;						//���� ���콺�� ��ǥ		

	_TCHAR						m_pszFrameRate[50];

public:			//������ ����
	void FrameAdvance();		//�����Ӹ��� �������� ����


};


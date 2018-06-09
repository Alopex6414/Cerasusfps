/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		Cerasusfps.h
* @brief	This File is Cerasusfps Dynamic Link Library Project.
* @author	alopex
* @version	v1.00a
* @date		2018-06-09	v1.00a	alopex	Create This File.
*/
#pragma once

#ifndef __CERASUSFPS_H_
#define __CERASUSFPS_H_

//Include DirectX Common Header File
#include "DirectCommon.h"
#include "DirectFont.h"
#include "DirectThreadSafe.h"

//Macro Definition
#ifdef CERASUSFPS_EXPORTS
#define CERASUSFPS_API	__declspec(dllexport)
#else
#define CERASUSFPS_API	__declspec(dllimport)
#endif

#define CERASUSFPS_CALL	__stdcall

//Class Definition
class CERASUSFPS_API CCerasusfps
{
private:
	DirectFont* m_pFont;	//Cerasusfps DirectFont(������ʽ)

	CRITICAL_SECTION m_cs;	//Cerasusfps Thread Safe(CriticalSection)
	bool m_bThreadSafe;		//Cerasusfps Thread Safe Status
	
private:
	float m_ffps;			//Cerasusfps Frame Per Second(֡����)

public:
	CCerasusfps();			//Cerasusfps Constructor Function(���캯��)
	~CCerasusfps();			//Cerasusfps Destructor Function(��������)

	CCerasusfps(IDirect3DDevice9* pD3D9Device);	//Cerasusfps Constructor Function(���캯��)(����+1)

	//����
	DirectFont* CERASUSFPS_CALL CCerasusfpsGetFont() const;		//Cerasusfps Get Font(��ȡ������)
	float CERASUSFPS_CALL CCerasusfpsGetFps() const;			//Cerasusfps Get Fps(��ȡfpsֵ)

	//����
	VOID CERASUSFPS_CALL CCerasusfpsSetFont(DirectFont* pFont);	//Cerasusfps Set Font(����������)

	//����
	HRESULT CERASUSFPS_CALL CCerasusfpsReset();					//Cerasusfps Reset(D3D��ʧ�豸Reset)

	//��ʼ��
	HRESULT CERASUSFPS_CALL CCerasusfpsInit(int nFontSize);							//Cerasusfps Initialize(��ʼ��)
	HRESULT CERASUSFPS_CALL CCerasusfpsInit(int nFontSize, LPWSTR lpszFontType);	//Cerasusfps Initialize(��ʼ��)(����+1)

	//����
	VOID CERASUSFPS_CALL CCerasusfpsGetfps();										//Cerasusfps Calculate Fps(����fps)
	VOID CERASUSFPS_CALL CCerasusfpsGetfpsEx(float fTimeDelta, float* pfps);		//Cerasusfps Calculate Fps Ex(����fps)
	VOID CERASUSFPS_CALL CCerasusfpsGetfpsEx(float* pfps);							//Cerasusfps Calculate Fps Ex(����fps)(����+1)
	float CERASUSFPS_CALL CCerasusfpsGetfpsEx(float fTimeDelta);					//Cerasusfps Calculate Fps Ex(����fps)(����+2)
	float CERASUSFPS_CALL CCerasusfpsGetfpsEx();									//Cerasusfps Calculate Fps Ex(����fps)(����+3)

	//����
	VOID CERASUSFPS_CALL CCerasusfpsDrawfps(HWND hWnd);									//Cerasusfps Draw Fps(����fps)
	VOID CERASUSFPS_CALL CCerasusfpsDrawfps(HWND hWnd, DWORD Format);					//Cerasusfps Draw Fps(����fps)(����+1)
	VOID CERASUSFPS_CALL CCerasusfpsDrawfps(HWND hWnd, DWORD Format, D3DCOLOR Color);	//Cerasusfps Draw Fps(����fps)(����+2)
};


#endif // !__CERASUSFPS_H_

// dllmain.cpp : Définit le point d'entrée pour l'application DLL.
#include "stdafx.h"
#include <tchar.h>

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{

	PLONG datalength = 0;
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		TCHAR buffer[MAX_PATH];
		// Get the name of the executable we're loading in
		GetModuleFileName(NULL, buffer, MAX_PATH);

		// Get the configured programs to disable Window Ghosting on
		if (buffer) {
			if (_tcsstr(buffer, _T("yourprogram.exe"))) {
				DisableProcessWindowsGhosting();
			}
		}

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


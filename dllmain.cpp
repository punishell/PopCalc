#include "header.h"

extern "C" __declspec(dllexport) void PopCalc() {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	CreateProcess(
		TEXT("C:\\Windows\\System32\\calc.exe"),
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CreateProcess(
			TEXT("C:\\Windows\\System32\\calc.exe"),
			NULL,
			NULL,
			NULL,
			FALSE,
			0,
			NULL,
			NULL,
			&si,
			&pi
		);
    case DLL_THREAD_ATTACH:

    case DLL_THREAD_DETACH:

    case DLL_PROCESS_DETACH:
        break;
    }

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
    return TRUE;
}


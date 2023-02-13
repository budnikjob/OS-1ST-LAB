#include <iostream>
#include <Windows.h>
#include <tchar.h>
#define BUFFER_SIZE 200

DWORD g_BytesTransferred = 0;

int wmain(int argc, WCHAR* argv[]) {
	
	HANDLE hFind;
	DWORD dwBytesRead = 0;
	char READ_BUFFER[BUFFER_SIZE] = { 0 };
	const wchar_t* PATH_TO_FILE = L"D:\\BSTU\\SP_LABS\\1st_lab\\OS09_01.txt";
	hFind = CreateFile(PATH_TO_FILE, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, // normal file
		NULL);
	dwBytesRead = g_BytesTransferred;
	if (dwBytesRead > 0 && dwBytesRead <= BUFFER_SIZE - 1) {
		_tprintf(TEXT("Data read from %s (%d bytes): \n"), PATH_TO_FILE, dwBytesRead);
		printf("%s\n", READ_BUFFER);
	}
	else if (dwBytesRead == 0) {
		_tprintf(TEXT("No data from file %s\n"), PATH_TO_FILE);
	}
	CloseHandle(hFind);
	return 1;
}
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <iostream>
#include <Windows.h>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
void main() {
	setlocale(LC_ALL, "Russian");
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	const wchar_t *PATH_TO = L"D:\\BSTU\\SP_LABS\\1st_lab\\OS09_01.txt";
    const fs::path PATH_TO1 = PATH_TO;
	hFind = FindFirstFile(PATH_TO, &FindFileData);
	const fs::path FILE_TYPE = PATH_TO1.extension();
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			SYSTEMTIME st, ut;
			SHFILEINFOW fileInfo = { 0 };
			SHGetFileInfoW(PATH_TO, NULL, &fileInfo, sizeof(fileInfo), SHGFI_TYPENAME | SHGFI_USEFILEATTRIBUTES);
			FileTimeToSystemTime(&FindFileData.ftCreationTime, &st);
			FileTimeToSystemTime(&FindFileData.ftLastWriteTime, &ut);
			std::wcout << "FILE NAME: " << FindFileData.cFileName << std::endl;
			std::wcout << "FILE SIZE: " << FindFileData.nFileSizeLow << " BYTES" << std::endl;
			std::wcout << "FILE EXTENSION: " << FILE_TYPE<< std::endl;
			std::wcout << "FILE TYPE: " << fileInfo.szTypeName<< std::endl;
			std::wcout << "CREATION TIME: " << st.wDay<< " " << st.wMonth << " " << st.wYear << " " << st.wHour << ":" << st.wMinute <<  ":" << st.wSecond << std::endl;
			std::wcout << "UPDATE TIME: " << ut.wDay<< " " << ut.wMonth << " " << ut.wYear << " " << ut.wHour << ":" << ut.wMinute <<  ":" << ut.wSecond << std::endl;
		} while (FindNextFile(hFind, &FindFileData) != 0);
		FindClose(hFind);
	}
}


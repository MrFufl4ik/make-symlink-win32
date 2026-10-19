//
// Created by mrfufl4ik on 10/19/26.
//

#ifndef MAKE_SYMLINK_WIN32_OUTPUT_H
#define MAKE_SYMLINK_WIN32_OUTPUT_H

#include <string>
#include <windows.h>

#define INVALID_HANDLE_VALUE_ERROR_CODE (8820 + 0)

void print(const std::wstring &string);
void println(const std::wstring &string);

DWORD createSymLink(const std::wstring &targetPath, const std::wstring &linkPath);

bool isDirectoryExists(const std::wstring &path);
bool isFileExists(const std::wstring &path);
bool isEntryExists(const std::wstring &path);


#endif //MAKE_SYMLINK_WIN32_OUTPUT_H
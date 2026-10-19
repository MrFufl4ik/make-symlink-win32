//
// Created by mrfufl4ik on 10/19/26.
//

#include "Api.h"

void print(const std::wstring &string) {
    HANDLE stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (stdOutput == INVALID_HANDLE_VALUE || stdOutput == nullptr) exit(INVALID_HANDLE_VALUE_ERROR_CODE);

    DWORD written = 0;
    DWORD consoleMode = 0;
    if (GetConsoleMode(stdOutput, &consoleMode)) {
        WriteConsoleW(stdOutput, string.c_str(), string.size(), &written, nullptr);
    } else {
        const int length = WideCharToMultiByte(
            CP_UTF8,
            0,
            string.c_str(),
            static_cast<int>(string.size()),
            nullptr, 0, nullptr, nullptr
        );
        if (length <= 0) return;
        std::string utf8(length, '\0');
        WideCharToMultiByte(
            CP_UTF8, 0,
            string.c_str(),
            static_cast<int>(string.size()),
            utf8.data(), length, nullptr, nullptr
        );
        WriteFile(stdOutput, utf8.data(), utf8.size(), &written, nullptr);
    }
}

void println(const std::wstring &string) {
    print(string + L"\r\n");
}

DWORD createSymLink(const std::wstring &targetPath, const std::wstring &linkPath) {
    DWORD flags = SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE;
    if (isDirectoryExists(targetPath)) flags |= SYMBOLIC_LINK_FLAG_DIRECTORY;
    const BOOLEAN result = CreateSymbolicLinkW(linkPath.c_str(), targetPath.c_str(), flags);
    if (!result) return GetLastError();
    return 0;
}

bool isDirectoryExists(const std::wstring &path) {
    const DWORD attributes = GetFileAttributesW(path.c_str());
    return attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY);
}

bool isFileExists(const std::wstring &path) {
    const DWORD attributes = GetFileAttributesW(path.c_str());
    return attributes != INVALID_FILE_ATTRIBUTES && !(attributes & FILE_ATTRIBUTE_DIRECTORY);
}

bool isEntryExists(const std::wstring &path) {
    return isDirectoryExists(path) || isFileExists(path);
}
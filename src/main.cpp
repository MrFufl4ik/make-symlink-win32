#include <string>
#include <windows.h>

#define INVALID_HANDLE_VALUE_ERROR_CODE (-8800 - 2)

void println(const std::wstring &s) {
    HANDLE stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (stdOutput == INVALID_HANDLE_VALUE || stdOutput == nullptr) exit(INVALID_HANDLE_VALUE_ERROR_CODE);

    const std::wstring string = s + L"\r\n";

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

int wmain(int argc, wchar_t *argv[]) {
    println(L"Hello, world!");
    return 0;
}

#include <string>

#include "windows/Api.h"

#define LOCAL_DIRECTORY_DOESNT_EXISTS_ERROR_CODE (8810 + 0)
#define USER_DONT_PASS_CORRECT_ARGUMENTS_ERROR_CODE (8810 + 1)

const std::wstring PROG_NAME = L"make-symlink-win32.exe";

void onUserDontPassCorrectArguments() {
    println(PROG_NAME + L": missing operand" );
    println(L"Try: " + PROG_NAME + L" targetPath linkPath");
}

int wmain(const int argc, wchar_t *argv[]) {
    if (argc != 1 /*first argument equal path to current binary*/ + 2) {
        onUserDontPassCorrectArguments();
        std::exit(USER_DONT_PASS_CORRECT_ARGUMENTS_ERROR_CODE);
    }
    const std::wstring targetPath {argv[1]};
    if (!isEntryExists(targetPath)) {
        println(L"Target entry " + targetPath + L" doesn't exist!");
        std::exit(LOCAL_DIRECTORY_DOESNT_EXISTS_ERROR_CODE);
    }
    const std::wstring linkPath {argv[2]};
    const DWORD result = createSymLink(targetPath, linkPath);
    if (result) {
        println(L"Error on symlink creation: " + std::to_wstring(result));
        std::exit(static_cast<int>(result));
    }
    println(L"Symlink " + linkPath + L" created successful!");
    return 0;
}

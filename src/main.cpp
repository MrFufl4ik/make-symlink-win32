#include <windows.h>

int WINAPI wWinMain(
    HINSTANCE,
    HINSTANCE,
    PWSTR,
    int
) {
    MessageBoxW(
        nullptr,
        L"Hello from WinAPI!",
        L"My application",
        MB_OK | MB_ICONINFORMATION
    );

    return 0;
}

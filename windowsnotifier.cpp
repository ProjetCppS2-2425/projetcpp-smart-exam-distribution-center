#include "windowsnotifier.h"
#include <windows.h>

void WindowsNotifier::showNativeToast(const QString& title, const QString& message, QWidget* parent) {
    HWND hwnd = parent ? reinterpret_cast<HWND>(parent->winId()) : nullptr;

    NOTIFYICONDATA nid{};
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hwnd;
    nid.uFlags = NIF_INFO | NIF_ICON;
    nid.dwInfoFlags = NIIF_USER | NIIF_LARGE_ICON;

    // Load default app icon
    nid.hIcon = LoadIcon(GetModuleHandle(nullptr), IDI_APPLICATION);

    // Convert strings to wide char
    wcsncpy_s(nid.szInfoTitle, title.toStdWString().c_str(), 64);
    wcsncpy_s(nid.szInfo, message.toStdWString().c_str(), 256);

    Shell_NotifyIcon(NIM_ADD, &nid);
    Shell_NotifyIcon(NIM_DELETE, &nid);  // Cleanup
}

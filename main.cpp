#define UNICODE
#include <windows.h>

// Hàm xử lý sự kiện
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1 && HIWORD(wParam) == BN_CLICKED) {
            MessageBox(hwnd, L"Bạn đã bấm nút!", L"Thông báo", MB_OK);
        }
        break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"SimpleWindowClass";

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0, CLASS_NAME, L"Cửa sổ đơn giản", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 150,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) return 0;

    CreateWindowW(L"BUTTON", L"Bấm vào đây",
        WS_VISIBLE | WS_CHILD,
        80, 40, 120, 30,
        hwnd, (HMENU)1, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

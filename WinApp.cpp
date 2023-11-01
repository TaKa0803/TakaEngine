#include"WinApp.h"
#include"Log.h"
#include<cstdint>

//ウィンドドウプロシーシャ
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}

WinApp* WinApp::GetInstance() {

	static WinApp instance;
	return &instance;

}

void WinApp::Initilaize(int32_t windowWidth, int32_t windowHeight) {
#pragma region ウィンドウ作成

	kClientWidth = windowWidth;
	kClientHeight = windowHeight;

	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = L"window";
	wc.hInstance = GetModuleHandle(nullptr);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

	RegisterClass(&wc);

	RECT wrc = { 0,0,windowWidth,windowHeight };

	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	hwnd = CreateWindow(
		wc.lpszClassName,
		L"a",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		wrc.right - wrc.left,
		wrc.bottom - wrc.top,
		nullptr,
		nullptr,
		wc.hInstance,
		nullptr
	);

	ShowWindow(hwnd, SW_SHOW);
#pragma endregion

#pragma region デバッグレイヤー有効
#ifdef _DEBUG
	if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)))) {
		debugController->EnableDebugLayer();
		debugController->SetEnableGPUBasedValidation(TRUE);
	}
#endif // _DEBUG

	
#pragma endregion

}

void WinApp::Finalize() {



	CloseWindow(hwnd);
}

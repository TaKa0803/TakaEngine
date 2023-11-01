#pragma once
#include<Windows.h>
#include <string>
#include<d3d12.h>
#include<wrl.h>

class WinApp {
public:
	static WinApp* GetInstance();
private:
	WinApp() = default;
	~WinApp() = default;
	WinApp(const WinApp& o) = delete;
	const WinApp& operator=(const WinApp& o) = delete;

public:

	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;


	int32_t kClientWidth=1280;
	int32_t kClientHeight=720;


	void Initilaize(int32_t windowWidth, int32_t windowHeight);

	void Finalize();
public:

	const HWND& GetHWND() { return hwnd; }

private:

	WNDCLASS wc{};

	HWND hwnd;

#ifdef _DEBUG
	ComPtr<ID3D12Debug1> debugController = nullptr;
#endif // _DEBUG
};
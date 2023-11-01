#include<Windows.h>
#include"MainEngine.h"

#include<dxgidebug.h>
#pragma comment(lib,"dxguid.lib")

#pragma region 構造体
struct D3DResourceLeakChecker {
	~D3DResourceLeakChecker() {
		//リソースリークチェック
		Microsoft::WRL::ComPtr<IDXGIDebug1>debug;
		if (SUCCEEDED(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&debug)))) {
			debug->ReportLiveObjects(DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_ALL);
			debug->ReportLiveObjects(DXGI_DEBUG_APP, DXGI_DEBUG_RLO_ALL);
			debug->ReportLiveObjects(DXGI_DEBUG_D3D12, DXGI_DEBUG_RLO_ALL);
			//警告時に止まる
		}
	}
};
#pragma endregion

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	static D3DResourceLeakChecker lackCheck;

	MainEngine *mainSystem = new MainEngine();

	mainSystem->Initialize();

	mainSystem->Run();

	mainSystem->Finalize();

	delete mainSystem;

	return 0;
}
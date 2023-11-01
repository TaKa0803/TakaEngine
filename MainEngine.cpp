#include "mainEngine.h"
#include<Windows.h>


void MainEngine::Initialize() {
	winApp_ = WinApp::GetInstance();
	winApp_->Initilaize(1280,720);

	dxClass_ = DirectXClass::GetInstance();
	dxClass_->Initialize(winApp_);
}

void MainEngine::Run() {

	while (ProcessMessage()) {
		dxClass_->PreDraw();

		dxClass_->PostDraw();
	}

}

void MainEngine::Finalize() {
	dxClass_->Finalize();
	winApp_->Finalize();
}

bool MainEngine::ProcessMessage() {
	MSG msg{};
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (msg.message != WM_QUIT) {

		return true;
	}
	else {
		return false;
	}
}

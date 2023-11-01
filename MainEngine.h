#pragma once
#include"WinApp.h"
#include"DirectXClass.h"

class MainEngine {

public:

	
	void Initialize();

	void Run();

	void Finalize();



private:
	bool ProcessMessage();


private:
	WinApp* winApp_ = nullptr;
	DirectXClass* dxClass_ = nullptr;
};
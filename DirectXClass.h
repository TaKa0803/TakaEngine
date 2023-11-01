#pragma once
#include<wrl.h>
#include"WinApp.h"
#include<d3d12.h>
#include<dxgi1_6.h>


class DirectXClass {
public:
	static DirectXClass* GetInstance();
private:
	DirectXClass() = default;
	~DirectXClass() = default;
	DirectXClass(const DirectXClass& o) = delete;
	const DirectXClass& operator=(const DirectXClass& o) = delete;


public:

	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;


	void Initialize(WinApp* winApp);

	void PreDraw();

	void PostDraw();

	void Finalize();
private:
	void InitializeDXDevice();

	void InitializeCMD();

	void InitializeSwapChain();

	void InitializeRTV();

	void InitializeFenceEvent();
private:

	WinApp* winApp_ = nullptr;

	
	
	ComPtr<IDXGIFactory7> dxgiFactory = nullptr;

	ComPtr<ID3D12Device>device = nullptr;

	ComPtr<ID3D12CommandQueue> commandQueue = nullptr;
	ComPtr<ID3D12CommandAllocator> commandAllocator = nullptr;
	ComPtr<ID3D12GraphicsCommandList> commandList = nullptr;

	ComPtr<IDXGISwapChain4> swapChain = nullptr;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	ComPtr<ID3D12Resource> swapChainResources[2] = { nullptr };

	ComPtr<ID3D12DescriptorHeap> rtvDescriptorHeap = nullptr;

	D3D12_CPU_DESCRIPTOR_HANDLE rtvHandles[2];


	D3D12_RESOURCE_BARRIER barrier{};

	ComPtr<ID3D12Fence> fence = nullptr;
	uint64_t fenceValue;
	HANDLE fenceEvent;

};
// testclient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <objbase.h>

// The method signature in this interface must be the same as in MathServer.cs.
// With the exception of return value: in C++ clients the return value must be presented as the last output parameter.
struct IServer : public IUnknown {
    virtual HRESULT Add(int num1, int num2, int* sum) = 0;
};
// Interface and CoClass GUIDs must be the same as in MathServer.cs.
static const GUID iid = { 0xC0B5F93D, 0xA766, 0x4B65, { 0xAE, 0x5F, 0xFC, 0x0A, 0xA0, 0xE6, 0xDB, 0xEB } };
static const GUID clsid = { 0xAE9DE624, 0x3FED, 0x45A2, { 0x87, 0xEB, 0x8A, 0x55, 0xFF, 0xB9, 0x3F, 0x77 } };

int main()
{
    CoInitialize(NULL); // STA client

    IServer* pServer = nullptr;
    HRESULT hr = CoCreateInstance(clsid, nullptr, CLSCTX_INPROC_SERVER, iid, reinterpret_cast<LPVOID*>(&pServer));
    if (SUCCEEDED(hr)) {
        int sum = 0;
        hr = pServer->Add(5, 3, &sum);
        if (SUCCEEDED(hr))
            std::cout << "COM math server returned sum: " << sum << std::endl;

        pServer->Release();
    }

    CoUninitialize();

    return 0;
}


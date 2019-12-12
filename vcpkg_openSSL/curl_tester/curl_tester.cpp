// curl_tester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "dll4test.h"
#include "windows.h"

typedef void(__cdecl* HelloBingType)();
HelloBingType FcnHello;
HMODULE dll_ = nullptr;
 
void LoadDLL() {
  TCHAR szFileName[MAX_PATH + 1] = {0};
  GetModuleFileName(NULL, szFileName, MAX_PATH + 1);
  std::wstring libPath(szFileName);
  libPath = libPath.substr(0, libPath.find_last_of(L"\\"));
  libPath.append(L"\\dll4test.dll");

  auto dll_ = LoadLibrary(libPath.c_str());
  if (dll_) {
    FcnHello = reinterpret_cast<HelloBingType>(
      ::GetProcAddress(dll_, "HelloBing"));
  }
}

void UnloadDLL() {
  if (dll_) {
    FreeLibrary(dll_);
    dll_ = nullptr;
  }
}

int main()
{
    LoadDLL();

    if (FcnHello) {
      FcnHello();
    }

    UnloadDLL();
}

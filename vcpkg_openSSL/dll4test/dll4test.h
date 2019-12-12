#pragma once

#ifndef DLL4TEST_EXPORTS
#define DLL4TESTDECL __declspec(dllimport)
#else
#define DLL4TESTDECL __declspec(dllexport)
#endif

extern "C"
{
 DLL4TESTDECL void HelloBing(void);
}
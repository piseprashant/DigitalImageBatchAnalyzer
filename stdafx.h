// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once

#pragma warning( push )
#pragma warning( disable:4677 )
#pragma warning( disable:4800 )
#pragma warning( disable:4793 )
#pragma warning( disable:4715 )


// TODO: reference additional headers your program requires here
//#include <Windows.h>
//#include <mscoree.h>
#define _CRT_SECURE_NO_DEPRECATE

#include <SDKDDKVer.h>

#include <stdio.h>

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

//#define _AFXDLL

#include <windows.h>

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

//#include <atlbase.h>
//#include <atlstr.h>

#include <vector>
#include <list>
#include <string.h>
//#include <atlstr.h>
///#include <cstringt.h>
#include <Shlwapi.h>
#include <iostream>



using namespace std;
// TODO: reference additional headers your program requires here

#pragma once

#ifdef CHOO_PLATFORM_WINDOWS
	#ifdef CHOO_BUILD_DLL
		#define CHOO_API __declspec(dllexport)
	#else
		#define CHOO_API __declspec(dllimport)
	#endif
#else
	#error trial-engine currently does not support other platforms than Windows
#endif

#define BIT(x) (1 << x)
#pragma once

#ifdef _WIN32
	#include <windows.h>  
#endif

#include "glm.hpp"
#include "ext.hpp"
// CRT
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <clocale>
#include <malloc.h>
#include <mbstring.h>
#include <string.h>
#include <tchar.h>
#include <stdint.h>

// STL containers
#include <vector>
#include <map>
#include <string>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

// STL algorithms & functions
#include <algorithm>
#include <functional>
#include <limits>
#include <future>

// type
typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned int		uint32;
#ifdef PLATFORM_WINDOWS
typedef unsigned __int64	uint64;
#else
typedef unsigned long long	uint64;
#endif
typedef signed char			int8;
typedef signed short		int16;
typedef signed int			int32;
#ifdef PLATFORM_WINDOWS
typedef signed __int64		int64;
#else
typedef long long			int64;
#endif
typedef unsigned char		uchar;
typedef unsigned short		ushort;
typedef unsigned int		uint;
typedef unsigned long		ulong;


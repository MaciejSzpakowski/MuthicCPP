#pragma once

#include "Private.h"

#ifdef _DEBUG
#pragma comment(lib, "dx2d_debug.lib")
#else
#pragma comment(lib, "dx2d.lib")
#endif

using namespace dx2d;

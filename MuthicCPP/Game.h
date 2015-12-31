#pragma once

#include "viva/Viva.h"
#include "winsock/winsock.h"

#ifdef _DEBUG
#pragma comment(lib, "viva/dx2d.lib")
#pragma comment(lib, "winsock/winsock.lib")
#else
#pragma comment(lib, "dx2d.lib")
#pragma comment(lib, "winsock.lib")

#endif

using namespace Viva;
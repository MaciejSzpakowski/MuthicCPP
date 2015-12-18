#pragma once

#include "Private.h"
#include <stdexcept>

#ifdef _DEBUG
#pragma comment(lib, "dx2d_debug.lib")
#pragma comment(lib, "winsock_debug.lib")
#else
#pragma comment(lib, "dx2d.lib")
#pragma comment(lib, "winsock.lib")

#endif

namespace game
{
	using dx2d::Core;
	using dx2d::DrawManager;
	using dx2d::Input;
	using dx2d::EventManager;

	using std::wstring;
	using std::map;
	using std::vector;
}
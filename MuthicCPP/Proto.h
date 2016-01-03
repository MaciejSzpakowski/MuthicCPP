#pragma once

#include "viva/Viva.h"
#include "winsock/winsock.h"
#include <memory>
#include <stdexcept>
#include <fstream>

#ifdef _DEBUG
#pragma comment(lib, "viva/dx2d.lib")
#pragma comment(lib, "winsock/winsock.lib")
#else
#pragma comment(lib, "dx2d.lib")
#pragma comment(lib, "winsock.lib")

#endif

using namespace Viva;
using std::unique_ptr;
using std::runtime_error;

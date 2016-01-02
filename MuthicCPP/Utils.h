#pragma once

#include "Proto.h"

namespace game
{
	using namespace Viva;

	namespace utils
	{
		// Remove all white spaces from front and back.
		wstring Trim(const wstring& str);

		void GetFontUv(vector<RECT>& uv);
	}
}

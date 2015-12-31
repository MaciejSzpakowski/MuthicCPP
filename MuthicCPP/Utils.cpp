#include "Utils.h"

#define ISWHITE(c) (c==' ' || c=='\t')

namespace game
{
	namespace utils
	{
		wstring rtrim(const wstring& input, int l, int r)
		{			
			if (ISWHITE(input[l]) && l<r)
				return rtrim(input, l + 1, r);
			else if (ISWHITE(input[r]) && l<r)
				return rtrim(input, l, r - 1);
			else
				return wstring(input.begin() + l, input.begin() + r + 1);
		}

		wstring Trim(const wstring& str)
		{
			return rtrim(str, 0, (int)str.length() - 1);
		}
	}
}
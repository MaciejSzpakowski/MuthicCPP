#pragma once
#include "Game_Proto.h"
#include <regex>

namespace game
{
	class Path
	{
	private:
		map<wstring, wstring> paths;
	public:
		// ctor
		Path(wstring _root);

		// returns path to "file" in directory "dir"
		wstring From(const wstring& dir, const wstring& file) const;
	};

	extern Path path;
}
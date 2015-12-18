#include "Path.h"

namespace game
{
	wstring makePath(const wstring& a, const wstring& b)
	{
		wstring path = a + L"/" + b + L"/";
		std::wregex r(L"(/)+");
		return std::regex_replace(path, r, L"/");
	}

	Path::Path(wstring _root)
	{
		paths[L"root"] = _root;
		paths[L"data"] = makePath(paths[L"root"],L"data");
		paths[L"save"] = makePath(paths[L"root"],L"save");
		paths[L"hero"] = makePath(paths[L"data"],L"hero");
		paths[L"mob"] = makePath(paths[L"data"],L"mob");
		paths[L"font"] = makePath(paths[L"data"],L"font");
		paths[L"map"] = makePath(paths[L"data"],L"map");
		paths[L"misc"] = makePath(paths[L"data"],L"misc");
		paths[L"item"] = makePath(paths[L"data"],L"item");
		paths[L"effect"] = makePath(paths[L"data"],L"effect");
	}

	wstring Path::From(const wstring& dir, const wstring& file) const
	{
		auto p = paths.find(dir);

		if (p == paths.end())
			throw std::runtime_error("Path::from()\nDirectory not found in paths");

		return p->second + file;
	}
}
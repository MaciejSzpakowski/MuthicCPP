#include "Path.h"

namespace game
{
	wstring makePath(const wstring& a, const wstring& b)
	{
		wstring path = a + L"/" + b + L"/";
		std::wregex r(L"(/)+");
		return std::regex_replace(path, r, L"/");
	}

	void Path::Init(wstring _root)
	{
		for (int i = _root.size() - 1; i >= 0; i--)
			if (_root[i] == L'\"')
				_root.erase(_root.begin() + i);

		Get().initialized = true;

		Get().paths[L"root"] = _root;
		Get().paths[L"data"] = makePath(Get().paths[L"root"],L"data");
		Get().paths[L"save"] = makePath(Get().paths[L"root"],L"save");
		Get().paths[L"hero"] = makePath(Get().paths[L"data"],L"hero");
		Get().paths[L"mob"] = makePath(Get().paths[L"data"],L"mob");
		Get().paths[L"font"] = makePath(Get().paths[L"data"],L"font");
		Get().paths[L"map"] = makePath(Get().paths[L"data"],L"map");
		Get().paths[L"misc"] = makePath(Get().paths[L"data"],L"misc");
		Get().paths[L"item"] = makePath(Get().paths[L"data"],L"item");
		Get().paths[L"effect"] = makePath(Get().paths[L"data"],L"effect");
	}

	wstring Path::From(const wstring& dir, const wstring& file)
	{
		if (!Get().initialized)
			throw std::runtime_error("Path::From()\nPath is not initialized");

		auto p = Get().paths.find(dir);

		if (p == Get().paths.end())
			throw std::runtime_error("Path::From()\nDirectory not found in paths");

		return p->second + file;
	}
}
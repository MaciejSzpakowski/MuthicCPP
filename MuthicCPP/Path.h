#pragma once
#include <regex>
#include <map>
#include <string>

namespace game
{
	using std::map;
	using std::wstring;

	class Path
	{
	private:
		map<wstring, wstring> paths;
		bool initialized;
		static Path& Get()
		{
			static Path instance;
			return instance;
		}
		Path() { initialized = false; }
	public:
		Path(Path const&) = delete;
		void operator=(Path const&) = delete;

		// initializes Path singleton
		static void Init(wstring _root);

		// returns path to "file" in directory "dir"
		static wstring From(const wstring& dir, const wstring& file);		
	};
}

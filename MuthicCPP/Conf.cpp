#include "Conf.h"

namespace game
{
	void ConfigFile::Init(const wstring& filepath)
	{
		std::wifstream file(filepath);
		wstring line;
		std::wregex r;
		std::wsmatch match;

		while (std::getline(file, line)) // read line by line
		{
			if (line.substr(0, 4) == L"root") // if line starts with "root"
			{
				r = std::wregex(L"\"([^\"]*)\""); // find something between ""
				if (std::regex_search(line, match, r)) // if found
				{
					Get().config.root = match[0]; // store it as root
					Get().config.root = Get().config.root.substr(1, Get().config.root.length() - 2); // remove ""
				}
			}
		}
	}

	Config ConfigFile::GetConfig()
	{
		return Get().config;
	}
}
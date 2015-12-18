#include "Conf.h"

namespace game
{
	ConfigFile::ConfigFile(const wstring& filepath)
	{
		std::wifstream file(filepath);
		wstring line;
		std::wregex r;
		std::wsmatch match;

		while (std::getline(file, line)) // read line by line
		{
			if (line.substr(0, 4) == L"root") // if line starts with "root"
			{
				r = std::wregex(L"\"(.)*\""); // find something between ""
				if (std::regex_match(line, match, r)) // if found
				{
					config.root = match[0]; // store it as root
					config.root = config.root.substr(1, config.root.length() - 2); // remove ""
				}
			}
		}
	}

	Config ConfigFile::GetConfig() const
	{
		return config;
	}
}
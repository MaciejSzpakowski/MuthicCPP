#include "Conf.h"
#include "Utils.h"

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
			auto e = line.find(L'=', 0);

			if (e != wstring::npos)
				Get().Add(utils::Trim(wstring(line.begin(), line.begin() + e)), utils::Trim(wstring(line.begin() + e + 1, line.end())));
		}
	}

	wstring ConfigFile::GetConfig(wstring name)
	{
		std::string msg;

		auto it = Get().config.find(name);
		if (it == Get().config.end())
		{
			msg = "Config not found: ";
			msg += std::string(name.begin(), name.end());
			throw std::runtime_error("Config not found");
		}

		return it->second;
	}
}
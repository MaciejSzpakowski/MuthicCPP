// for config file
#pragma once
#include "Game_Proto.h"
#include <iostream>
#include <fstream>
#include <regex>

namespace game
{
	struct Config
	{
		wstring root;
	};

	class ConfigFile
	{
	private:
		Config config;
	public:
		ConfigFile(const wstring& filepath);

		Config GetConfig() const;
	};

	extern ConfigFile configFile;
}

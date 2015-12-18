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
		bool initialized;
		ConfigFile() { initialized = false; }

		static ConfigFile& Get()
		{
			static ConfigFile instance;
			return instance;
		}
	public:
		ConfigFile(ConfigFile const&) = delete;
		void operator=(ConfigFile const&) = delete;

		// initializes ConfigFile singleton
		static void Init(const wstring& filepath);

		// gets a copy of Config
		static Config GetConfig();
	};
}

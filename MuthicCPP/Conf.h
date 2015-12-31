// for config file
#pragma once
#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <stdexcept>
#include "Utils.h"

namespace game
{
	using std::wstring;
	using std::map;

	class ConfigFile
	{
	private:
		map<wstring,wstring> config;
		bool initialized;
		ConfigFile() { initialized = false; }

		void Add(const wstring& key, const wstring& value)
		{ 
			config[key] = value;
		}

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
		static wstring GetConfig(wstring name);
	};
}

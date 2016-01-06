#pragma once

#include "Mob.h"
#include "Hero.h"
#include "Map.h"

namespace game
{
	struct Room
	{
		vector<unique_ptr<Mob>> mobs;
		vector<unique_ptr<Hero>> heroes;
	};

	class Server
	{
	private:
		map<MapType, Room> rooms;
	public:
		Server(const GlobalAssets& g);
	};
}

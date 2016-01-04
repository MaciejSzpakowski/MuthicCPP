#pragma once

#include "Mob.h"
#include "Hero.h"

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
		vector<Room> rooms;
	public:
	};
}

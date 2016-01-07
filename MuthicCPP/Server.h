#pragma once

#include "Mob.h"
#include "Hero.h"
#include "Map.h"
#include "Player.h"

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
		Player* player;
		map<MapType, Room> rooms;
		vector<winsock::Client> clients;
		winsock::Server server;
		Event* netEvent;
		Event* updatePlayerPosEvent;

		void NetworkActivity();
	public:
		Server(const GlobalAssets& g, Player* p);

		~Server();
	};
}

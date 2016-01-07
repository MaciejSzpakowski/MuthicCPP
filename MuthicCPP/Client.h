#pragma once

#include "Server.h"

namespace game
{
	class Client
	{
	private:
		Player* player;
		Room room;
		winsock::Client client;
		Event* netActivity;
	public:
		Client(const GlobalAssets& g, Player* p);

		void ProcessMessage(const vector<byte>& msg);

		~Client();
	};
}

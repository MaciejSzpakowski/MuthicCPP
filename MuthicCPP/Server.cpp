#include "Server.h"

namespace game
{
	Server::Server(const GlobalAssets& g)
	{
		rooms[MapType::Lorencia] = Room();

		//hardcoded mobs

		rooms[MapType::Lorencia].mobs.push_back(unique_ptr<Mob>(new Mob(MobClass::BudgeDragon,g)));
	}
}
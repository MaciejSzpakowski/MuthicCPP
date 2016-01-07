#include "Server.h"

namespace game
{
	Server::Server(const GlobalAssets& g, Player* p)
	{
		player = p;
		server = winsock::Server(g.port);
		server.Start();

		rooms[MapType::Lorencia] = Room();

		//hardcoded mobs

		rooms[MapType::Lorencia].mobs.push_back(unique_ptr<Mob>(new Mob(MobClass::BudgeDragon,g)));

		// start network activity
		netEvent = EventManager->AddEvent([=]
		{
			NetworkActivity();
			return 1;
		}, L"netActivity", 0, 0, 0);

		// start updating pos
		updatePlayerPosEvent = EventManager->AddEvent([=]
		{
			XMFLOAT3 pos = p->GetHero()->GetCollider()->GetPosition();
			std::string spos = std::to_string(pos.x) +" " +std::to_string(pos.y);

			for (auto& c : clients)
			{
				c.Send((byte*)spos.c_str(), (byte)spos.length());
			}
			return 1;
		}, L"updatePos", 0, 0, 1);
	}

	void Server::NetworkActivity()
	{
		winsock::Client c;
		std::vector<byte> msg;

		try // get all errors
		{
			server.ThrowNextError();
		}
		catch (winsock::socket_error err)
		{
			printf("%s\n", err.what());			
		}

		if (server.GetNextClient(c)) // accept clients
		{
			printf("New client: %lld@%s\n", c.GetId(), c.GetIP().c_str());
			clients.push_back(c);
		}

		for (int i = (int)clients.size() - 1; i >= 0; i--) // check for disconnected clients
		{
			if (!clients[i].IsConnected())
			{
				printf("%lld@%s disconnected\n", clients[i].GetId(), clients[i].GetIP().c_str());
				clients.erase(clients.begin() + i);
			}
		}

		for (auto& c : clients)
		{
			try
			{
				c.ThrowNextError(); // get errors
			}
			catch (winsock::socket_error err)
			{
				printf("%s\n", err.what());
				printf("New client: %lld@%s\n", c.GetId(), c.GetIP().c_str());
			}

			if (c.GetNextMessage(msg)) // if there is a new message from that client
			{
				//text = std::string(msg.begin(), msg.end());
				//printf("%s: %s\n", c.GetIP().c_str(), text.c_str());

				//for (auto& other : clients) // resend
				//{
				//	try
				//	{
				//		if (other.GetId() != c.GetId())
				//			other.Send(msg.data(), msg.size());
				//	}
				//	catch (winsock::socket_error err)
				//	{
				//		printf("%s\n", err.what());
				//	}
				//}

				//msg.clear();
			}
		}
	}

	Server::~Server()
	{
		EventManager->RemoveEvent(netEvent);
		EventManager->RemoveEvent(updatePlayerPosEvent);
	}
}
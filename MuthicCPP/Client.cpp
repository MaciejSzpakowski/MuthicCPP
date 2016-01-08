#include "Client.h"

namespace game
{
	Client::Client(const GlobalAssets& g, Player* p)
	{
		player = p;

		try
		{
			client = winsock::Client(g.ip, g.port);
			client.Connect(3000);
			printf("connected to server\n");
		}
		catch (winsock::socket_error err)
		{
			printf("%s\n", err.what());
		}

		netActivity = EventManager->AddEvent([=]
		{
			vector<byte> msg;

			if (!client.IsConnected())
				printf("You are disconnected from the server\n");

			while(client.GetNextMessage(msg))
				ProcessMessage(msg);

			return 1;
		}, L"clientNetActivity", 0, 0, 0);
	}

	void Client::ProcessMessage(const vector<byte>& msg)
	{
		std::string text;

		text = std::string(msg.begin(), msg.end());
		printf("%s\n", text.c_str());
	}

	Client::~Client()
	{
		EventManager->RemoveEvent(netActivity);
	}
}
#include "Conf.h"
#include "Path.h"
#include "Utils.h"
#include "Player.h"
#include "Server.h"
#include "Client.h"
#include "MainMenu.h"

namespace game
{
	void Activity()
	{
		Sleep(1);
	}

	void GlobalEvents()
	{
		// fps event
		EventManager->AddEvent([]
		{
			double fps = Core->GetFps();
			Core->SetWindowTitle(std::to_wstring(fps).c_str());
			return 1;
		}, L"", 0, 0, 1);
	}

	void InitSingletons()
	{
		ConfigFile::Init(L"config.txt");
		Path::Init(ConfigFile::GetConfig(L"root"));
	}

	void InitGlobals(GlobalAssets& g)
	{
		vector<RECT> uv;
		utils::GetFontUv(uv);
		g.font = new BitmapFont(Path::From(L"font", L"font.png").c_str(), uv);
		g.fm.horizontalSpacing = 0.048f;
		g.fm.height = 1;
		g.fm.horizontalAlign = HorizontalAlignment::Left;
		g.fm.verticalAlign = VerticalAlignment::Top;
		g.fm.verticalSpacing = 0;
		g.fm.width = 1;
		g.world = DrawManager->AddRenderTarget();
	}

	void InitAndRun(std::vector<std::string> args)
	{
		GlobalAssets g;
		unique_ptr<Player> player;
		unique_ptr<Server> server;
		unique_ptr<Client> client;
		
		
		Core->OpenConsole();
		GlobalEvents();
		InitSingletons();
		InitGlobals(g);
		
		MainMenu mainMenu;
		mainMenu.FirstMenu(g);

		EventManager->AddEvent([&]
		{
			if (InputManager->IsKeyReleased(Keys::MouseLeft))
				printf("Mouse left released\n");

			if (InputManager->IsKeyDown(Keys::MouseLeft))
			{
				DebugManager->Debug(L"Mouse down", L"");
			}

			if (InputManager->IsKeyPressed(Keys::Key1))
			{
				g.gameType = GameType::Server;
				g.port = 10000;
				player = unique_ptr<Player>(Player::Deserialize(Path::From(L"save", L"Poteflon.hero").c_str(), g));
				server = unique_ptr<Server>(new Server(g,player.get()));
				return 0;
			}
			else if (InputManager->IsKeyPressed(Keys::Key2))
			{
				g.gameType = GameType::Client;
				g.port = 10000;
				g.ip = "127.0.0.1";
				player = unique_ptr<Player>(Player::Deserialize(Path::From(L"save", L"Poteflon.hero").c_str(), g));
				client = unique_ptr<Client>(new Client(g,player.get()));
				return 0;
			}
			return 1;
		}, L"", 0, 0, 0);		

		Core->Run();
	}
}
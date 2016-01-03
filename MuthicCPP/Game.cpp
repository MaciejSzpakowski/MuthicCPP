#include "Conf.h"
#include "Path.h"
#include "Utils.h"
#include "Player.h"

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
		std::unique_ptr<Player> player;
		
		Core->OpenConsole();
		GlobalEvents();
		InitSingletons();
		InitGlobals(g);

		//player = std::unique_ptr<Player>(new Player(L"Poteflon", HeroClass::Elf, g));
		//player->Serialize();
		player = std::unique_ptr<Player>(Player::Deserialize(Path::From(L"save", L"Poteflon.hero").c_str(), g));

		Core->Run();
	}
}
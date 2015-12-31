#include "Game.h"
#include "Conf.h"

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

	void InitAndRun(std::vector<std::string> args)
	{
		Viva::Functions::InitViva(Size(800, 600), Activity);
		GlobalEvents();
		InitSingletons();

		Core->Run();
		Core->Destroy();
	}
}
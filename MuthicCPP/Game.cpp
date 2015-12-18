#include "Game_Proto.h"
#include "Path.h"
#include "Conf.h"

namespace game
{
	void Activity()
	{
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
		Path::Init(ConfigFile::GetConfig().root);
	}

	void InitAndRun(std::vector<std::string> args)
	{
		dx2d::Functions::InitCore(800, 600, Activity);
		GlobalEvents();
		InitSingletons();

		Core->Run();
		Core->Destroy();
	}
}
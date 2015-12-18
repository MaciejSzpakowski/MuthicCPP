#include "Game_Proto.h"
#include "Path.h"

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
		path = Path(L"");
	}

	void InitAndRun(std::vector<std::string> args)
	{
		Functions::InitCore(800, 600, Activity);
		GlobalEvents();
		path = Path(L"");

		Core->Run();
		Core->Destroy();
	}
}
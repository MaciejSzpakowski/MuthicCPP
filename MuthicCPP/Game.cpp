#include "Game.h"

namespace game
{
	void Activity()
	{
	}

	void InitAndRun(std::vector<std::string> args)
	{
		Functions::InitCore(800, 600, Activity);

		auto c1 = DrawManager->AddCircle(2, 10);
		c1->Color = Color(1, 1, 1, 1);

		Core->Run();
		Core->Destroy();
	}
}
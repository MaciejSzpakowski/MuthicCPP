#include "Game.h"

namespace game
{
	void InitAndRun(std::vector<std::string> args);
}

int main(int argc, char** argv)
{
	std::vector<std::string> args;
	
	for (int i = 0; i < argc; i++)
		args.push_back(argv[i]);

	game::InitAndRun(args);

	return 0;
}
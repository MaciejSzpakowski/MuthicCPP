#include "Proto.h"

namespace game
{
	void InitAndRun(std::vector<std::string> args);
	void Activity();
}

int main(int argc, char** argv)
{
	std::vector<std::string> args;
	
	for (int i = 0; i < argc; i++)
		args.push_back(argv[i]);

	try
	{
		Viva::Functions::InitViva(Size(800, 600), game::Activity);
		game::InitAndRun(args);
		Viva::Core->Destroy();
	}
	catch (VivaError v)
	{
		std::string s = v.function;
		s += "\n";
		s += v.what();
		MessageBoxA(0, s.c_str(), "Error", MB_ICONEXCLAMATION);
	}
	catch (std::runtime_error r)
	{
		MessageBoxA(0,r.what(), "Error", MB_ICONEXCLAMATION);
	}

	return 0;
}
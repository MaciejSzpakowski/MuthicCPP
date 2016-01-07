#pragma once

#include "Proto.h"

using namespace Viva;

namespace game
{
	enum class GameType
	{
		Server, Client
	};

	struct GlobalAssets
	{
		RenderTarget* world;
		BitmapFont* font;
		BitmapFont* fontBold;
		FontMetrics fm;
		wstring playerFile;
		GameType gameType;
		unsigned short port;
		std::string ip;
	};	
}

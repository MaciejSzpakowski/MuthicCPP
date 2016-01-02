#pragma once

#include "Proto.h"

using namespace Viva;

namespace game
{
	struct GlobalAssets
	{
		RenderTarget* world;
		BitmapFont* font;
		BitmapFont* fontBold;
		FontMetrics fm;
		wstring playerFile;
	};
}

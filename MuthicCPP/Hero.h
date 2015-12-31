#pragma once

#include "Game.h"

namespace game
{
	class Hero
	{
	private:
		Circle* collider;
		Sprite* sprite;
		wstring name;
	public:
		Hero(const wstring& name, RenderTarget* world);

		void Activity();

		void Destroy();
	};
}
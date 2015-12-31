#include "Hero.h"

namespace game
{
	Hero::Hero(const wstring& name, RenderTarget* world)
	{
		collider = DrawManager->AddCircle(1,6);
		
	}

	void Hero::Activity()
	{
	}

	void Hero::Destroy()
	{
		collider->Destroy();
		sprite->Destroy();
	}
}
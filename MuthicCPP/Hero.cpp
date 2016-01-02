#include "Hero.h"
#include "Path.h"

namespace game
{
	Hero::Hero(const wstring& name, const wchar_t* filename, const GlobalAssets& g)
		:Character(1.5f, filename, name, g)
	{
		sprite->SetPixelScale(Size(32, 32));
		sprite->SetSize(4);

		activityEvent = EventManager->AddEvent([=]
		{
			Activity();
			return 1;
		}, name + wstring(L"heroActivity"), 0, 0, 0);
	}

	void Hero::Activity()
	{
		Move();
		AnimationControl();
	}

	void Hero::AnimationControl()
	{
	}

	wstring Hero::GetSpriteName(HeroClass c)
	{
		if (c == HeroClass::Elf)
			return Path::From(L"hero", L"elf.png");
		else if (c == HeroClass::Knight)
			return Path::From(L"hero", L"knight.png");
		else if (c == HeroClass::Wizard)
			return Path::From(L"hero", L"wizard.png");
		else
			throw std::runtime_error("Hero::GetSpriteName()\nWhat are you doing ?");
	}

	Hero::~Hero()
	{
		EventManager->RemoveEvent(activityEvent);
	}
}
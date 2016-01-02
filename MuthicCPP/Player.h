#pragma once

#include "Hero.h"

namespace game
{
	class Player
	{
	private:
		std::unique_ptr<Hero> hero;
		HeroClass heroClass;
		Event* activityEvent;
		float walkSpeed;
	public:
		Player(const wstring& name, HeroClass _heroClass, const GlobalAssets& g);

		// save player to file
		void Serialize(const wchar_t* filename);

		void Activity();
		void Control();

		~Player();
	};
}

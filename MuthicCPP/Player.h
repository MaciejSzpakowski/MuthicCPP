#pragma once

#include "Hero.h"

namespace game
{
	struct KeyBindings
	{
		Keys left;
		Keys right;
		Keys up;
		Keys down;
	};

	class Player
	{
	private:
		KeyBindings bindings;
		std::unique_ptr<Hero> hero;
		HeroClass heroClass;
		Event* activityEvent;
		float walkSpeed;

	public:
		Player(const wstring& name, HeroClass _heroClass, const GlobalAssets& g);

		// save player to file
		void Serialize();

		static Player* Deserialize(const wchar_t* filename, const GlobalAssets& g);

		Hero* GetHero() const { return hero.get(); }

		void Activity();
		void Control();

		~Player();
	};
}

#pragma once

#include "Global.h"
namespace game
{
	class MainMenu
	{
	private:
		Sprite* sp;
	public:
		 MainMenu();

		void FirstMenu(const GlobalAssets &g);

		void CharacterCreationMenu( const GlobalAssets &g);


		~MainMenu();
	};
}
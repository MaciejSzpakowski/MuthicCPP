#pragma once

#include "Character.h"

namespace game
{
	enum class HeroClass : int { Elf=1, Wizard=2, Knight=3 };

	class Hero : public Character
	{
	private:
		Event* activityEvent;
	public:
		Hero(const wstring& name, const wchar_t* filename, const GlobalAssets& g);

		void Activity();
		void AnimationControl() override;

		// translates heroclass to sprite name: e.g. HeroClass::Elf -> /data/hero/elf.png
		static wstring GetSpriteName(HeroClass c);

		~Hero();
	};
}

#pragma once

#include "Character.h"

namespace game
{
	enum class HeroClass : int { Invalid=0, Elf=1, Wizard=2, Knight=3 };

	class Hero : public Character
	{
	private:
		float aniWalkSpeed;
		Event* activityEvent;
		long long netid;
	public:
		Hero(const wstring& name, const wchar_t* filename, const GlobalAssets& g);

		void Activity();
		void AnimationControl() override;

		// translates heroclass to sprite name: e.g. HeroClass::Elf -> /data/hero/elf.png
		static wstring GetSpriteName(HeroClass c);

		~Hero();
	};
}

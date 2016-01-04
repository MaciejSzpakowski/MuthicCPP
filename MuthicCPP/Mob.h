#pragma once

#include "Character.h"

namespace game
{
	struct MapElem
	{
		wstring name;
		wstring file;
	};

	enum class MobClass : int
	{
		BudgeDragon = 1
	};

	class Mob : public Character
	{
	private:
		MobClass mobClass;
		long long netid;
		float aniWalkSpeed;
	public:
		Mob(MobClass c, const GlobalAssets& g);

		static MapElem MapClass2Elem(MobClass c);

		void AnimationControl() override;
	};
}

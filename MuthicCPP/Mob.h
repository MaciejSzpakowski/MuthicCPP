#pragma once

#include "Character.h"

namespace game
{
	struct MapElem
	{
		wstring name;
		wstring filename;
	};

	enum class MobClass : int
	{
		BudgeDragon = 1
	};

	class Mob : public Character
	{
	private:
		Event* activityEvent;
		MobClass mobClass;
		long long netid;
		float aniWalkSpeed;
	public:
		Mob(MobClass c, const GlobalAssets& g);

		static MapElem MapClass2Elem(MobClass c);

		void Activity();

		void AnimationControl() override;

		~Mob();
	};
}

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

	enum class MobState : int
	{
		Roaming = 1,
		Chasing = 2,
		Attacking = 3
	};

	class Mob : public Character
	{
	private:
		MobState state;
		Event* activityEvent;
		Event* pickNextTargetEvent;
		MobClass mobClass;
		long long netid;
		float aniWalkSpeed;

		void Behaviour();
		void AnimationControl() override;
		void Activity();
		void PickNextTarget();
	public:
		Mob(MobClass c, const GlobalAssets& g);

		static MapElem MapClass2Elem(MobClass c);
		
		~Mob();
	};
}

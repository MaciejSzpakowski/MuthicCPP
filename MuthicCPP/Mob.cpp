#include "Mob.h"
#include "Path.h"

namespace game
{
	Mob::Mob(MobClass c, const GlobalAssets& g)
		:Character(1.0f,MapClass2Elem(c).filename.c_str(), MapClass2Elem(c).name,g)
	{
		aniWalkSpeed = 6;

		activityEvent = EventManager->AddEvent([=]
		{
			Activity();
			return 1;
		}, name + wstring(L"heroActivity"), 0, 0, 0);
	}

	void InitMap(map<MobClass, MapElem>& mapping)
	{
		mapping[MobClass::BudgeDragon] = { L"Budge Dragon",Path::From(L"mob",L"budge_dragon.png") };
	}

	void Mob::Activity()
	{
		AnimationControl();
	}

	MapElem Mob::MapClass2Elem(MobClass c)
	{
		static map<MobClass, MapElem> mapping;

		if (mapping.size() == 0)
			InitMap(mapping);

		return mapping[c];
	}

	void Mob::AnimationControl()
	{
		XMFLOAT3 v = collider->GetVelocity();

		if (v.x == 0 && v.y == 0) // standing
		{
			sprite->SetSpeed(0);
			sprite->SetCurrentFrame(1);
		}
		else                  // walking
		{
			sprite->SetBegin(0);
			sprite->SetEnd(1);
			sprite->SetSpeed(aniWalkSpeed);
		}

		if (v.x > 0)
			sprite->SetFlipHorizontally(true);
		else if (v.x < 0)
			sprite->SetFlipHorizontally(false);
	}

	Mob::~Mob()
	{
		EventManager->RemoveEvent(activityEvent);
	}
}

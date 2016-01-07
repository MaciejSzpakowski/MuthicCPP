#include "Mob.h"
#include "Path.h"

namespace game
{
	Mob::Mob(MobClass c, const GlobalAssets& g)
		:Character(1.0f,MapClass2Elem(c).filename.c_str(), MapClass2Elem(c).name,g)
	{
		aniWalkSpeed = 6;
		moveSpeed = DirectX::XMVectorSet(5, 5, 5, 5);
		state = MobState::Roaming;
		sprite->SetPixelScale(Size(32, 32));
		sprite->SetSize(3);

		activityEvent = EventManager->AddEvent([=]
		{
			if (g.gameType == GameType::Server)
				Behaviour();
			Activity();
			return 1;
		}, name + wstring(L"mobActivity"), 0, 0, 0);

		pickNextTargetEvent = EventManager->AddEvent([=]
		{
			PickNextTarget();
			return 0;
		}, name + wstring(L"pickNextTarget"), Random::RndDouble() * 2 + 2, 0, 0);
	}

	void InitMap(map<MobClass, MapElem>& mapping)
	{
		mapping[MobClass::BudgeDragon] = { L"Budge Dragon",Path::From(L"mob",L"budge_dragon.png") };
	}

	void Mob::PickNextTarget()
	{
		if (state == MobState::Roaming)
		{
			auto pos = collider->_GetPositionVector();
			auto offset = DirectX::XMVectorSet((float)Random::RndDouble() * 16 - 8, 
				                               (float)Random::RndDouble() * 16 - 8, 0, 1);
			target = DirectX::XMVectorAdd(pos, offset);
		}

		pickNextTargetEvent = EventManager->AddEvent([=]
		{
			PickNextTarget();
			return 0;
		}, name + wstring(L"pickNextTarget"), Random::RndDouble() * 2 + 2, 0, 0);
	}

	void Mob::Activity()
	{
		Move();
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

	void Mob::Behaviour()
	{

	}

	Mob::~Mob()
	{
		EventManager->RemoveEvent(activityEvent);
		EventManager->RemoveEvent(pickNextTargetEvent);
	}
}

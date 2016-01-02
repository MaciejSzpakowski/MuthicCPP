#include "Player.h"
#include "Path.h"
#include <fstream>

namespace game
{
	Player::Player(const wstring& name, HeroClass _heroClass, const GlobalAssets& g)
	{
		hero = std::unique_ptr<Hero>(new Hero(name, Hero::GetSpriteName(_heroClass).c_str(), g));

		activityEvent = EventManager->AddEvent([=]
		{
			Activity();
			return 1;
		}, L"playerActivity", 0, 0, 0);

		walkSpeed = 7;
		hero->SetMoveSpeed(walkSpeed);
	}

	void Player::Serialize(const wchar_t* filename)
	{
		std::ofstream file;
		file.open(filename, std::ios::binary | std::ios::trunc);
		file << "1";
		file.close();
	}

	void Player::Activity()
	{
		Control();
	}

	void Player::Control()
	{
		XMFLOAT3 pos = hero->GetCollider()->GetPosition();
		bool left = InputManager->IsKeyDown(Keys::Left);
		bool right = InputManager->IsKeyDown(Keys::Right);
		bool up = InputManager->IsKeyDown(Keys::Up);
		bool down = InputManager->IsKeyDown(Keys::Down);

		if (left)
			pos.x -= 1;
		else if (right)
			pos.x += 1;

		if (up)
			pos.y += 1;
		else if (down)
			pos.y -= 1;

		hero->SetTarget(pos);
	}

	Player::~Player()
	{
		EventManager->RemoveEvent(activityEvent);
	}
}
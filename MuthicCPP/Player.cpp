#include "Player.h"
#include "Path.h"
#include "Utils.h"
#include <fstream>

namespace game
{
	Player::Player(const wstring& name, HeroClass _heroClass, const GlobalAssets& g)
	{
		bindings.down = Keys::Down;
		bindings.left = Keys::Left;
		bindings.right = Keys::Right;
		bindings.up = Keys::Up;

		heroClass = _heroClass;

		hero = std::unique_ptr<Hero>(new Hero(name, Hero::GetSpriteName(_heroClass).c_str(), g));

		activityEvent = EventManager->AddEvent([=]
		{
			Activity();
			return 1;
		}, L"playerActivity", 0, 0, 0);

		walkSpeed = 7;
		hero->SetMoveSpeed(walkSpeed);
	}

	void Player::Serialize()
	{		
		wstring filename = hero->GetName();
		filename += L".hero";
		filename = Path::From(L"save", filename);
		
		std::ofstream file;
		file.open(filename, std::ios::binary | std::ios::trunc);
		utils::WriteBinary(file, (int*)(&heroClass));
		utils::WriteBinary(file, hero->GetName());
		file.close();
	}

	Player* Player::Deserialize(const wchar_t* filename, const GlobalAssets& g)
	{
		HeroClass c = HeroClass::Invalid;
		wstring name;

		std::ifstream file;
		file.open(filename, std::ios::binary);

		if (!file.is_open())
		{
			wstring fstr = filename;
			std::string msg = "Could not open ";
			msg += std::string(fstr.begin(),fstr.end());
			throw runtime_error(msg.c_str());
		}

		utils::ReadBinary(file, (int*)&c);
		utils::ReadBinary(file, &name);
		file.close();

		return new Player(name, c, g);
	}

	void Player::Activity()
	{
		Control();
	}

	void Player::Control()
	{
		XMFLOAT3 pos = hero->GetCollider()->GetPosition();
		bool left = InputManager->IsKeyDown(bindings.left);
		bool right = InputManager->IsKeyDown(bindings.right);
		bool up = InputManager->IsKeyDown(bindings.up);
		bool down = InputManager->IsKeyDown(bindings.down);

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
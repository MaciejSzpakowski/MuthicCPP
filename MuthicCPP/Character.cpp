#include "Character.h"

namespace game
{
	Character::Character(float radius, const wchar_t* filename, const wstring& _name, const GlobalAssets& g)
	{
		name = _name;
		moveSpeed = DirectX::XMVectorSet(1, 1, 1, 1);

		collider = DrawManager->AddCircle(radius, 6);
		collider->SetColor(Color(1, 0, 0, 1));
		target = collider->_GetPositionVector();

		sprite = DrawManager->AddAnimation(filename, 3, 1, g.world);
		sprite->SetParent(collider);

		label = DrawManager->AddBitmapText(g.font);
		label->SetMetrics(g.fm);
		label->SetText(name);
		label->SetColor(Color(1, 0, 0, 1));
		label->SetParent(collider);
		label->SetPositionY(2);
	}

	void Character::Move()
	{
		auto diff = DirectX::XMVectorSubtract(target,collider->_GetPositionVector());
		auto vlensq = DirectX::XMVector2LengthSq(diff);
		float lensq;
		DirectX::XMStoreFloat(&lensq, vlensq);
		if (lensq > 0.001f)
		{
			diff = DirectX::XMVector4Normalize(diff);
			diff = DirectX::XMVectorMultiply(diff, moveSpeed);
			collider->SetVelocity(diff);
		}
		else
			collider->SetVelocity(0,0,0);
	}

	Character::~Character()
	{
		collider->Destroy();
		sprite->Destroy();
		label->Destroy();
	}
}
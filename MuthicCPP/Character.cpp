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
		auto v = DirectX::XMVectorSubtract(target,collider->_GetPositionVector());
		v = DirectX::XMVector4Normalize(v);
		v = DirectX::XMVectorMultiply(v, moveSpeed);
		collider->SetVelocity(v);
	}

	Character::~Character()
	{
		collider->Destroy();
		sprite->Destroy();
		label->Destroy();
	}
}
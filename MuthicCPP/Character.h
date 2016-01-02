#pragma once

#include "Global.h"

namespace game
{
	// moving and collider
	class Character
	{
	protected:
		XMVECTOR target;
		Circle* collider;
		Animation* sprite;
		wstring name;
		BitmapText* label;
		float moveSpeed;
	public:
		Character(float radius, const wchar_t* filename, const wstring& _name, const GlobalAssets& g);
		virtual void AnimationControl() = 0;
		void Move();

		wstring GetName() const { return name; }
		void SetName(const wstring& n) { name = n; }
		Circle* GetCollider() const { return collider; }
		void SetTarget(const XMFLOAT3& v) { target = DirectX::XMVectorSet(v.x, v.y, v.z, 0); }
		Animation* GetSprite() const { return sprite; }
		void SetMoveSpeed(float s) { moveSpeed = s; }

		~Character();
	};
}

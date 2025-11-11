#pragma once

#include "Game/Entities/Collectible/Collectible.h"

namespace addScore
{

	class AddScore : public collectible::Collectible
	{
	private:
		int addAmount;

	public:
		AddScore(Vector2 pos);
		~AddScore() override;

		void onColEntity(entity::Entity* ent) override;
	};
}


#pragma once

#include "Game/Entities/Collectible/Collectible.h"

namespace multiplyScore
{
	class MultiplyScore : public collectible::Collectible
	{
	private: 
		int multiplyAmount;
	public:
		MultiplyScore(Vector2 pos);
		~MultiplyScore() override;

		void onColEntity(entity::Entity* ent) override;
	};
}


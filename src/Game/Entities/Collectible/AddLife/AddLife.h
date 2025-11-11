#pragma once

#include "Game/Entities/Collectible/Collectible.h"

namespace addLife
{
	class AddLife : public collectible::Collectible
	{
	private:
		int lifeAmount;
	public:
		AddLife(Vector2 pos);
		~AddLife() override;

		void onColEntity(entity::Entity* ent) override;
	};
}


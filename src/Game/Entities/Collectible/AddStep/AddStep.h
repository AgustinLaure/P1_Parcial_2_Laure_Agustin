#pragma once

#include "Game/Entities/Collectible/Collectible.h"

namespace addStep
{
	class AddStep : public collectible::Collectible
	{
	private:
		int addStep;
	public:
		AddStep(Vector2 pos);
		~AddStep() override;

		void onColEntity(entity::Entity* ent) override;
	};
}



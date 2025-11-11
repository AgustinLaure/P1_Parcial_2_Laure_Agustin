#pragma once

#include "Game/Entities/Player/Player.h"

namespace obstacle
{
	class Obstacle : public entity::Entity
	{
	private:
		int damage;
	public:
		Obstacle(Vector2 pos);
		~Obstacle();

		void onColEntity(Entity* ent) override;
	};
}





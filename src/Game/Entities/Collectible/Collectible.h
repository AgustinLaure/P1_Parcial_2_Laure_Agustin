#pragma once

#include "Game/Entities/Player/Player.h"

namespace collectible
{
	const int maxCollectibleTypes = 4;

	class Collectible : public entity::Entity
	{
	private:
		bool isOn;

	public:
		Collectible(Vector2 pos, Color color);
		virtual ~Collectible() override;

		void reset(Vector2 pos);
		bool getIsOn();

		virtual void onColEntity(entity::Entity* ent) override;
	};
}


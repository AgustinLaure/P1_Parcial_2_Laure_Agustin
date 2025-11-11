#include "Game/Entities/Collectible/Collectible.h"

namespace collectible
{
	Collectible::Collectible(Vector2 pos, Color color) : entity::Entity(pos, color), isOn(true) {}

	Collectible::~Collectible() {};

	void Collectible::reset(Vector2 pos)
	{
		isOn = true;
		body.pos = pos;
	}

	bool Collectible::getIsOn() { return isOn; }

	void Collectible::onColEntity(entity::Entity* ent)
	{
		player::Player* player = dynamic_cast<player::Player*>(ent);

		if (player)
		{
			isOn = false;
		}
	}
}

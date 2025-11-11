#include "Game/Entities/Collectible/AddLife/AddLife.h"

namespace addLife
{
	const Color addLifeColor = GREEN;
	
	AddLife::AddLife(Vector2 pos) : collectible::Collectible(pos, addLifeColor), lifeAmount(1) {}
	AddLife::~AddLife() {}

	void AddLife::onColEntity(entity::Entity* ent)
	{
		collectible::Collectible::onColEntity(ent);

		player::Player* player = dynamic_cast<player::Player*>(ent);

		if (player)
		{
			player->heal(lifeAmount);
		}
	}
}
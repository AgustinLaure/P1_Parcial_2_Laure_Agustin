#include "Game/Entities/Collectible/AddScore/AddScore.h"

namespace addScore
{
	const Color addScoreColor = BLUE;

	const int minAddAmount = 10;
	const int maxAddAmount = 20;

	AddScore::AddScore(Vector2 pos) : collectible::Collectible(pos, addScoreColor), addAmount(GetRandomValue(minAddAmount, maxAddAmount)) {}
	AddScore::~AddScore() {}

	void AddScore::onColEntity(entity::Entity* ent)
	{
		collectible::Collectible::onColEntity(ent);

		player::Player* player = dynamic_cast<player::Player*>(ent);

		if (player)
		{
			player->addScore(addAmount);
		}
	}
}

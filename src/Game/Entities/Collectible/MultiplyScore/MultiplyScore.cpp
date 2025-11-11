#include "Game/Entities/Collectible/MultiplyScore/MultiplyScore.h"

namespace multiplyScore
{
	const Color mutiplyScoreColor = PURPLE;

	const int minMultiplyAmount = 2;
	const int maxMultiplyAmount = 3;

	MultiplyScore::MultiplyScore(Vector2 pos) : collectible::Collectible(pos, mutiplyScoreColor), multiplyAmount(GetRandomValue(minMultiplyAmount, maxMultiplyAmount)) {}
	MultiplyScore::~MultiplyScore() {}

	void MultiplyScore::onColEntity(entity::Entity* ent)
	{
		collectible::Collectible::onColEntity(ent);

		player::Player* player = dynamic_cast<player::Player*>(ent);

		if (player)
		{
			player->multiplyScore(multiplyAmount);
		}
	}
}

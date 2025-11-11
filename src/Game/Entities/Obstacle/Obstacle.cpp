#include "Game/Entities/Obstacle/Obstacle.h"

namespace obstacle
{
	int obstacleDamage = 1;
	const Color obstacleColor = RED;

	Obstacle::Obstacle(Vector2 pos) : entity::Entity(pos, obstacleColor), damage(obstacleDamage) {}
	Obstacle::~Obstacle() {}

	void Obstacle::onColEntity(Entity* ent)
	{
		player::Player* player = dynamic_cast<player::Player*>(ent);

		if (player)
		{
			player->takeDamage(damage);
		}
	}
}

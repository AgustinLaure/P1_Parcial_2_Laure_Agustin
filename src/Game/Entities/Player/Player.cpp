#include "Game/Entities/Player/Player.h"

#include "Screen/Screen.h"
#include "Game/Entities/Collectible/Collectible.h"

namespace player
{
	const float playerStep = 15.0f;
	const int iniLives = 3;
	const int iniMoves = 30;

	Player::Player(Vector2 pos, Color color) : entity::Entity(pos, color), lives(iniLives), maxLives(lives), score(0), movesLeft(iniMoves), isAlive(true), isHittable(true), collectedCollectibles(0) {}
	Player::~Player() {}

	int Player::getLives() { return lives; }
	int Player::getMaxLives() { return maxLives; }
	int Player::getScore() { return score; }
	int Player::getMovesLeft() { return movesLeft; }
	bool Player::getIsAlive() { return lives > 0 && movesLeft > 0; }
	int Player::getCollectedCollectibles() { return collectedCollectibles; }

	void Player::onColEntity(entity::Entity* ent)
	{
		collectible::Collectible* collectible = dynamic_cast<collectible::Collectible*>(ent);

		if (collectible)
		{
			collectedCollectibles++;
		}
	}

	void Player::takeDamage(int amount)
	{
		if (isHittable)
		{
			lives -= amount;
			isHittable = false;

			if (lives < 0)
			{
				lives = 0;
				isAlive = false;
			}
		}
	}

	void Player::heal(int amount)
	{
		lives += amount;

		if (lives > maxLives)
		{
			lives = maxLives;
		}
	}

	void Player::addScore(int amount) { score += amount; }

	void Player::multiplyScore(int amount) { score *= amount; }

	void Player::addStep(int amount) { movesLeft += amount; }

	void Player::move()
	{
		Vector2 nextPos = body.pos;

		bool moved = false;

		if (IsKeyPressed(KEY_W))
		{
			nextPos.y += -playerStep;
			moved = true;
		}
		if (IsKeyPressed(KEY_A))
		{
			nextPos.x += -playerStep;
			moved = true;
		}
		if (IsKeyPressed(KEY_S))
		{
			nextPos.y += playerStep;
			moved = true;
		}
		if (IsKeyPressed(KEY_D))
		{
			nextPos.x += playerStep;
			moved = true;
		}

		if (moved && screen::isInLimits(nextPos))
		{
			body.pos = nextPos;
			isHittable = true;
			movesLeft--;
		}
	}
}

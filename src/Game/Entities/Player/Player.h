#pragma once

#include "Game/Entities/Entity.h"

namespace player
{
	class Player : public entity::Entity
	{
	private:
		int lives;
		int maxLives;
		int score;
		int movesLeft;
		bool isAlive;
		bool isHittable;
		int collectedCollectibles;

	public:
		Player(Vector2 pos, Color color);
		~Player() override;

		int getLives();
		int getMaxLives();
		int getScore();
		int getMovesLeft();
		bool getIsAlive();
		int getCollectedCollectibles();
		void onColEntity(Entity* ent) override;
		void takeDamage(int amount);
		void heal(int amount);
		void addScore(int amount);
		void multiplyScore(int amount);
		void addStep(int amount);

		void move();
	};
}


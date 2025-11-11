#pragma once

#include <vector>

#include "Game/Entities/Collectible/Collectible.h"

namespace game
{
	class Game
	{
	private:
		bool isGameRunning;
		bool gameLost;
		player::Player* player;
		std::vector<entity::Entity*> entities;
		std::vector<collectible::Collectible*> collectibles;

		void update();
		void draw();
		void drawHUD();
		bool isValidPlacement(entity::Entity* ent);
		Vector2 getRandomPos();
		void result();

	public:
		Game();
		~Game();
		void run();

	};
}


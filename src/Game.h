#pragma once

#include "raylib.h"

#include "Entity.h"

namespace game
{
	const int maxEntities = 10;

	class Game
	{
	private:
		entity::Entity* entities[maxEntities] = {};

		void update();
		void draw();
	public:
		Game();
		void run();

	};
}


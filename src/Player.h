#pragma once

#include "Entity.h"

namespace player
{
	class Player : public entity::Entity
	{
	private:
		void move();
	public:
		Player(form::Rectangle body);
		~Player();
		void update();
		void draw();

	};
}


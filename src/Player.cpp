#include "Player.h"

namespace player
{
	void Player::move()
	{

	}

	Player::Player(form::Rectangle body) : entity::Entity(body) {}
	Player::~Player() {}

	void Player::update()
	{

	}

	void Player::draw()
	{
		DrawRectangle(body.pos.x, body.pos.y, body.width, body.height, color);
	}
}

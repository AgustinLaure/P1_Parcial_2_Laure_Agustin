#include "Game/Entities/Entity.h"

namespace entity
{
	const float width = 15;
	const float height = 15;

	Entity::Entity(Vector2 pos, Color color) : body(form::Rectangle(pos,width,height)), color(color){}

	Entity::~Entity() {}

	bool Entity::isCol(Entity* ent)
	{
		return body.pos.x + body.width > ent->body.pos.x
			&& body.pos.x < ent->body.pos.x + ent->body.width
			&& body.pos.y < ent->body.pos.y + ent->body.height
			&& body.pos.y + body.height > ent->body.pos.y;
	}

	Color Entity::getColor() { return color; }
	form::Rectangle Entity::getBody() { return body; }

	void Entity::move(Vector2 pos)
	{
		body.pos = pos;
	}

	void Entity::draw()
	{
		DrawRectangle(static_cast<int>(body.pos.x), static_cast<int>(body.pos.y), static_cast<int>(body.width), static_cast<int>(body.height), color);
	}
}
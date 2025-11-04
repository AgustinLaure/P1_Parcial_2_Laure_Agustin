#include "Entity.h"

namespace entity
{
	Entity::Entity(form::Rectangle body) : body(body) {}
	Entity::~Entity() {}

	bool Entity::isColEntity(Entity ent)
	{
		return body.isColRect(ent.body);
	}
}
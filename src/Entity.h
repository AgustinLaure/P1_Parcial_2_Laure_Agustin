#include "Form.h"

namespace entity
{
	class Entity
	{
	public:
		form::Rectangle body;
		Entity(form::Rectangle body);
		~Entity();
		bool isColEntity(Entity ent);
	};
}
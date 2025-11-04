#include "Form.h"

namespace entity
{
	class Entity
	{
	private:

	public:
		Color color = WHITE;
		form::Rectangle body;

		Entity(form::Rectangle body);
		~Entity();
		bool isColEntity(Entity ent);
		Color getColor();
	};
}
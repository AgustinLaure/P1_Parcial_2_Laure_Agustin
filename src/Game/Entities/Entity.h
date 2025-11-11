#include "Math/Form/Form.h"

namespace entity
{
	class Entity
	{
	protected:
		form::Rectangle body;
		Color color = WHITE;
		
	public:
		Entity(Vector2 pos, Color color);
		virtual ~Entity();

		bool isCol(Entity* ent);
		Color getColor();
		form::Rectangle getBody();
		void move(Vector2 pos);

		void draw();

		virtual void onColEntity(Entity* ent) = 0;
	};
}
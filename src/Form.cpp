#include "Form.h"

namespace form
{
	bool Rectangle::isColRect(Rectangle rect)
	{
		bool isColX = false;
		bool isColY = false;

		if (rect.pos.x < pos.x)
		{
			isColX = rect.pos.x + rect.width > pos.x;
		}
		else if (rect.pos.x > pos.x)
		{
			isColX = rect.pos.x < pos.x + width;
		}

		if (rect.pos.y < pos.y)
		{
			isColY = rect.pos.y + rect.height > pos.y;
		}
		else if (rect.pos.y > pos.y)
		{
			isColY = rect.pos.y < pos.y + rect.height;
		}

		return isColX && isColY;
	}
}
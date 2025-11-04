#pragma once

#include "raylib.h"

namespace form
{
	class Rectangle
	{
	public:
		Vector2 pos = {};
		float width = 0.0f;
		float height = 0.0f;
	
		bool isColRect(Rectangle rect);
	};
}


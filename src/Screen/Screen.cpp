#include "Screen/Screen.h"

namespace screen
{
	bool isInLimits(Vector2 pos)
	{
		return pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height;
	}
}
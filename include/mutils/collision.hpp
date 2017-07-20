#pragma once

#include "vec2.hpp"

namespace mutils
{
	bool isInAABB(Vec2 p, Vec2 aabbTopLeft, Vec2 aabbBottomRight);

	bool isInCircle(Vec2 p, Vec2 center, float radius);
}
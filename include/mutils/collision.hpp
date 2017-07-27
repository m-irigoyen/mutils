#pragma once

#include <mutils/vec2.hpp>
#include <SFML\Graphics\Rect.hpp>

namespace mutils
{
	bool isInAABB(Vec2 p, sf::FloatRect);
	bool isInAABB(Vec2 p, Vec2 aabbTopLeft, Vec2 aabbBottomRight);

	bool isInCircle(Vec2 p, Vec2 center, float radius);
}

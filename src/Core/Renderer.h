#pragma once

#include <vector>

#include "../math_lib.h"

namespace Renderer
{
	void begin();
	void end();
	void drawTriangles(const std::vector<math_lib::Vec2>& vertices, const std::vector<unsigned int>& indices);
	void drawCircles(const math_lib::Vec2& center, const float radius);
	void drawText(const char* text, unsigned int fontSize, const math_lib::Vec2& position);
}


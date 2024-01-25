#include "Renderer.h"

#include "raylib.h"

namespace Renderer
{
	void begin()
	{
		BeginDrawing();
		ClearBackground(BLACK);
	}

	void end()
	{		
		EndDrawing();
	}

	void drawTriangles(const std::vector<math_lib::Vec2>& vertices, const std::vector<unsigned int>& indices)
	{
		for (unsigned int i = 0; i < indices.size(); i += 3)
		{
			DrawTriangle(
				{ vertices[indices[i]].x(), vertices[indices[i]].y() },
				{ vertices[indices[i + 1]].x(), vertices[indices[i + 1]].y() },
				{ vertices[indices[i + 2]].x(), vertices[indices[i + 2]].y() },
				GREEN
			);
		}
	}

	void drawCircles(const math_lib::Vec2& center, const float radius)
	{
		DrawCircle(center.x(), center.y(), radius, RAYWHITE);
	}
	void drawText(const char* text, unsigned int fontSize, const math_lib::Vec2& position)
	{
		DrawText(text, position.x(), position.y(), fontSize, RAYWHITE);
	}
}
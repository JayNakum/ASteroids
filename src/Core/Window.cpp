#include "Window.h"

#include "raylib.h"

void Window::update()
{
	if (IsWindowResized())
	{
		m_screenWidth = GetScreenWidth();
		m_screenHeight = GetScreenHeight();
	}
}

Window::Window(int width, int height)
	: m_screenWidth(width), m_screenHeight(height)
{
	InitWindow(m_screenWidth, m_screenHeight, "ASteroids");
	int display = GetCurrentMonitor();
	SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
	ToggleFullscreen();
	SetTargetFPS(m_FPS);

	m_screenWidth = GetScreenWidth();
	m_screenHeight = GetScreenHeight();
}

Window::~Window()
{
	CloseWindow();
}

bool Window::isClosed() const
{
	if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose())
		return true;
	return false;
}

#include "raylib.h"

#include "Core/Renderer.h"
#include "Core/Window.h"

#include "Entities/Asteroids.h"
#include "Entities/Cannon.h"
#include "Entities/Player.h"

#include "math_lib/random.h"

#include <chrono>
#include <string>
#include <thread>

class Application
{
public:
	Application()
		: m_cannon(10)
	{
		m_camera = { 0 };
		m_camera.target = { 0, 0 };
		m_camera.offset = { m_mainWindow.width() / 2.0f, m_mainWindow.height() / 2.0f };
		m_camera.zoom = 1.0f;
		m_camera.rotation = 0.0f;

		m_gameState = false;
		m_score = 0;
	}

	void play()
	{
		std::thread spawner(&Application::_spawner, this);
		while (!m_mainWindow.isClosed())
		{
			m_mainWindow.update();
			if (m_gameState)
			{
				_handleEvents();

				m_player.update();
				m_cannon.update();
				m_asteroids.update();

				_checkCollision();

				_drawWorld();
			}
			else
			{
				_drawMenu();
			}
		}
		spawner.join();
	}

private:
	void _spawner() {
		uint32_t seed = 1234567890;
		while (!m_mainWindow.isClosed())
		{
			if (m_gameState && m_asteroids.getCount() < m_asteroids.MAX_COUNT)
			{
				float x = randomFloat(seed, 0.0f, 1.0f) * m_mainWindow.width() - (m_mainWindow.width() / 2.0f);
				float y = randomFloat(seed, 0.0f, 1.0f) * m_mainWindow.height() - (m_mainWindow.height() / 2.0f);
				m_asteroids.spawn({ x + 250.0f , y + 250.0f });
				if (m_asteroids.getCount() > 3)
					std::this_thread::sleep_for(std::chrono::seconds(2));
			}
		}
	}

	void _handleEvents()
	{
		if (IsKeyDown(KEY_LEFT))
			m_player.rotate(-3);
		if (IsKeyDown(KEY_RIGHT))
			m_player.rotate(3);
		if (IsKeyPressed(KEY_SPACE) && m_cannon.bulletsLeft)
			m_cannon.fire(m_player.fireDirection());
	}

	void _checkCollision()
	{
		for (Asteroid& asteroid : m_asteroids.getAsteroids())
		{
			if (CheckCollisionPointCircle({ 0.0f, 0.0f },
				{ asteroid.position.x(), asteroid.position.y() }, asteroid.radius()))
			{
				m_gameState = false;
				m_asteroids.clear();
				m_cannon.clear();
				break;
			}

			for (Bullet& bullet : m_cannon.getBullets())
			{
				if (CheckCollisionCircles(
					{ asteroid.position.x(), asteroid.position.y() }, asteroid.radius(),
					{ bullet.position.x(), bullet.position.y() }, bullet.radius())
					)
				{
					asteroid.destroy = true;
					bullet.destroy = true;
					m_score++;
					if (asteroid.radius() < 30)
						m_cannon.bulletsLeft += 1;
					m_cannon.bulletsLeft += 1;
				}
			}
		}
	}

	void _drawWorld()
	{
		std::string myScore = "Score: " + std::to_string(m_score);
		std::string bullets = "Bullets: " + std::to_string(m_cannon.bulletsLeft);
		Renderer::begin();
		{
			Renderer::drawText(myScore.c_str(), 24, { 20, 20 });
			int width = MeasureText(bullets.c_str(), 24);
			Renderer::drawText(bullets.c_str(), 24, { (float)m_mainWindow.width() - width, 20 });
			BeginMode2D(m_camera);
			{
				m_player.draw();
				for (Bullet& bullet : m_cannon.getBullets())
				{
					if ((bullet.position.x() < -(m_mainWindow.width() / 2.0f) || bullet.position.x() > (m_mainWindow.width() / 2.0f)) ||
						(bullet.position.y() < -(m_mainWindow.height() / 2.0f) || bullet.position.y() > (m_mainWindow.height() / 2.0f)))
						bullet.destroy = true;
					else
						bullet.draw();
				}

				for (Asteroid& asteroid : m_asteroids.getAsteroids())
				{
					if (asteroid.position.x() < -(m_mainWindow.width() / 2.0f) - asteroid.radius())
					{
						asteroid.position[0] = (m_mainWindow.width() / 2.0f) + asteroid.radius();
					}
					else if (asteroid.position.x() > (m_mainWindow.width() / 2.0f) + asteroid.radius())
					{
						asteroid.position[0] = -(m_mainWindow.width() / 2.0f) - asteroid.radius();
					}

					if (asteroid.position.y() < -(m_mainWindow.height() / 2.0f) - asteroid.radius())
					{
						asteroid.position[1] = (m_mainWindow.height() / 2.0f) + asteroid.radius();
					}
					else if (asteroid.position.y() > (m_mainWindow.height() / 2.0f) + asteroid.radius())
					{
						asteroid.position[1] = -(m_mainWindow.height() / 2.0f) - asteroid.radius();
					}

					asteroid.draw();
				}
			}
			EndMode2D();
		}
		Renderer::end();
	}

	void _drawMenu()
	{
		Renderer::begin();
		{
			int width = MeasureText("ASTEROIDS", 72);
			Renderer::drawText("ASTEROIDS", 72, { (m_mainWindow.width() / 2.0f) - (width / 2.0f), m_mainWindow.height() / 2.0f });
			std::string previousScore = "Score: " + std::to_string(m_score);
			width = MeasureText(previousScore.c_str(), 26);
			Renderer::drawText(previousScore.c_str(), 26, { (m_mainWindow.width() / 2.0f) - (width / 2.0f), (m_mainWindow.height() / 2.0f) + width });
		}
		Renderer::end();
		if (IsKeyPressed(KEY_SPACE))
		{
			m_score = 0;
			m_gameState = true;
		}
	}

private:
	Window m_mainWindow;
	Camera2D m_camera;

	Player m_player;
	Cannon m_cannon;
	Asteroids m_asteroids;

	bool m_gameState;
	int m_score;
};

int main()
{
	Application* game = new Application();
	game->play();
	delete game;
}

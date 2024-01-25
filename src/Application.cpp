#include "raylib.h"

#include "Core/Window.h"
#include "Core/Renderer.h"

#include "Entities/Player.h"
#include "Entities/Cannon.h"
#include "Entities/Asteroids.h"

#include "math_lib/random.h"

#include <chrono>
#include <thread>
#include <string>

int main()
{
	Window mainWindow;
	
	Camera2D camera = { 0 };
	camera.target = { 0, 0 };
	camera.offset = { mainWindow.width() / 2.0f, mainWindow.height() / 2.0f };
	camera.zoom = 1.0f;
	camera.rotation = 0.0f;

	Player player;
	Cannon cannon(10);
	Asteroids asteroids;

	bool gameState = false;
	int score = 0;

	uint32_t seed = 1234567890;
	std::thread spawner([&]() {
		while (!mainWindow.isClosed())
		{
			if (gameState)
			{
				float x = randomFloat(seed, 0.0f, 1.0f) * mainWindow.width() - mainWindow.width() / 2.0f;
				float y = randomFloat(seed, 0.0f, 1.0f) * mainWindow.height() - mainWindow.height() / 2.0f;
				asteroids.spawn({ x + 150.0f , y + 150.0f });
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		}
	});

	while (!mainWindow.isClosed())
	{
		mainWindow.update();
		if (gameState)
		{
			if (IsKeyDown(KEY_LEFT))
				player.rotate(-3);
			if (IsKeyDown(KEY_RIGHT))
				player.rotate(3);
			if (IsKeyPressed(KEY_SPACE))
				cannon.fire(player.fireDirection());

			player.update();
			cannon.update();
			asteroids.update();
			

			for (Asteroid& asteroid : asteroids.getAsteroids())
			{
				if (CheckCollisionPointCircle({ 0.0f, 0.0f },
					{ asteroid.position.x(), asteroid.position.y() }, asteroid.radius()))
				{
					gameState = false;
					asteroids.clear();
					
					break;
				}

				for (Bullet& bullet : cannon.getBullets())
				{
					if (CheckCollisionCircles(
						{ asteroid.position.x(), asteroid.position.y() }, asteroid.radius(),
						{ bullet.position.x(), bullet.position.y() }, bullet.radius())
						)
					{
						asteroid.destroy = true;
						bullet.destroy = true;
						score++;
					}
				}
			}

			std::string myScore = "Score: " + std::to_string(score);
			Renderer::begin();
			{
				Renderer::drawText(myScore.c_str(), 24, {20, 20});
				BeginMode2D(camera);
				{
					player.draw();
					for (Bullet& bullet : cannon.getBullets())
					{
						if ((bullet.position.x() < -(mainWindow.width() / 2.0f) || bullet.position.x() > (mainWindow.width() / 2.0f)) ||
							(bullet.position.y() < -(mainWindow.height() / 2.0f) || bullet.position.y() > (mainWindow.height() / 2.0f)))
							bullet.destroy = true;
						else
							bullet.draw();
					}

					for (Asteroid& asteroid : asteroids.getAsteroids())
					{
						if ((asteroid.position.x() < -(mainWindow.width() / 2.0f) || asteroid.position.x() > (mainWindow.width() / 2.0f)) ||
							(asteroid.position.y() < -(mainWindow.height() / 2.0f) || asteroid.position.y() > (mainWindow.height() / 2.0f)))
							asteroid.destroy = true;
						else
							asteroid.draw();
					}
				}
				EndMode2D();
			}
			Renderer::end();
		}
		else
		{
			Renderer::begin();
			{
				int width = MeasureText("ASTEROIDS", 72);
				Renderer::drawText("ASTEROIDS", 72, { (mainWindow.width() / 2.0f) - (width / 2.0f), mainWindow.height() / 2.0f });
				std::string previousScore = "Score: " + std::to_string(score);
				width = MeasureText(previousScore.c_str(), 26);
				Renderer::drawText(previousScore.c_str(), 26, { (mainWindow.width() / 2.0f) - (width / 2.0f), (mainWindow.height() / 2.0f) + width });
			}
			Renderer::end();
			if (IsKeyPressed(KEY_SPACE))
			{
				score = 0;
				gameState = true;
			}
		}
	}
	spawner.join();
}

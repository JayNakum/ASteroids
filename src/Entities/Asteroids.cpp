#include "Asteroids.h"

#include "../Core/Renderer.h"

#include "../math_lib/random.h"

Asteroid::Asteroid(const math_lib::Vec2& direction, float speed, unsigned int radius)
	: m_direction(direction), m_speed(speed), m_radius(radius) {}

void Asteroid::draw() const
{
	Renderer::drawCircles(position, m_radius);
}

void Asteroid::update()
{
	position = position + (m_direction * m_speed);
}

void Asteroids::update()
{
	for (auto& asteroid : m_asteroids)
	{
		if (asteroid.destroy)
		{
			auto pos = std::find(m_asteroids.begin(), m_asteroids.end(), asteroid);
			if (pos != m_asteroids.end())
				m_asteroids.erase(pos);
		}
		asteroid.update();
	}
}

void Asteroids::spawn(const math_lib::Vec2& position)
{
	unsigned int seed = position.x() * position.y();

	math_lib::Vec2 direction(0.0f - position.x(), 0.0f - position.y());
	direction = direction * (1 / direction.magnitude());

	float speed = randomFloat(seed, 2.0f, 4.0f);
	unsigned int radius = (unsigned int) randomFloat(seed, 25.0f, 50.0f);
	
	Asteroid newAsteroid(direction, speed, radius + 25);
	newAsteroid.ID = m_asteroids.size();
	newAsteroid.position = position;

	m_asteroids.push_back(newAsteroid);
}

Asteroids::~Asteroids()
{
	m_asteroids.clear();
}


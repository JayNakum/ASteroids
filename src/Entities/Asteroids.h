#pragma once

#include "Entity.h"

#include "../math_lib.h"

#include <vector>

class Asteroid : public Entity
{
public:
	unsigned int ID = 0;

	Asteroid(const math_lib::Vec2& direction, float speed, unsigned int radius = 25);
	void draw() const override;
	void update();

	inline const math_lib::Vec2 direction() const { return m_direction; }
	inline const unsigned int radius() const { return m_radius; }

	bool operator ==(const Asteroid& asteroid)
	{
		return (position.x() == asteroid.position.x() && position.y() == asteroid.position.y());
	}

private:private:
	math_lib::Vec2 m_direction;
	float m_speed;
	unsigned int m_radius;
};

class Asteroids
{
public:
	void update();
	void spawn(const math_lib::Vec2& position);

	inline std::vector<Asteroid>& getAsteroids() { return m_asteroids; }

	inline void clear() { m_asteroids.clear(); }
	~Asteroids();

private:
	std::vector<Asteroid> m_asteroids;
};
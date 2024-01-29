#pragma once

#include "Entity.h"

#include "../math_lib/math_lib.h"

#include <vector>

class Bullet : public Entity
{
public:
	unsigned int ID = 0;

	Bullet(const math_lib::Vec2& direction, unsigned int radius = 5);
	void draw() const override;
	
	inline const math_lib::Vec2 direction() const { return m_direction; }
	inline const unsigned int radius() const { return m_radius; }

	bool operator ==(const Bullet& bullet)
	{
		return (position.x() == bullet.position.x() && position.y() == bullet.position.y());
	}

private:
	math_lib::Vec2 m_direction;
	unsigned int m_radius;
};

class Cannon
{
public:
	Cannon(float power = 1.0f);
	~Cannon();

	void update();
	void fire(const math_lib::Vec2& direction);
	inline std::vector<Bullet>& getBullets() { return m_bulletsFired; }
	inline void clear() { m_bulletsFired.clear(); }
	unsigned int bulletsLeft = 11;

private:
	std::vector<Bullet> m_bulletsFired;
	float m_power;
};

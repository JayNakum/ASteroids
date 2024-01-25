#include "Cannon.h"

#include "../Core/Renderer.h"

Bullet::Bullet(const math_lib::Vec2& direction, unsigned int radius)
	: m_direction(direction), m_radius(radius) {}

void Bullet::draw() const
{
	Renderer::drawCircles(position, m_radius);
}

Cannon::Cannon(float power)
	: m_power(power) {}

Cannon::~Cannon()
{
	m_bulletsFired.clear();
}

void Cannon::update()
{
	for (auto& bullet : m_bulletsFired)
	{
		if (bullet.destroy)
		{
			auto pos = std::find(m_bulletsFired.begin(), m_bulletsFired.end(), bullet);
			if (pos != m_bulletsFired.end())
				m_bulletsFired.erase(pos);
		}
		bullet.position = bullet.position + (bullet.direction() * m_power);
	}
}

void Cannon::fire(const math_lib::Vec2& direction)
{
	Bullet newBullet(direction);
	newBullet.ID = m_bulletsFired.size();
	m_bulletsFired.push_back(newBullet);
}

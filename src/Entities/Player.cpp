#include "Player.h"

#include "../Core/Renderer.h"

Player::Player()
{
	scale(50);
	// rotate(180);
}

void Player::draw()	const
{
	Renderer::drawTriangles(m_vertices, m_indices);
}

void Player::update()
{
	//if (m_model != math_lib::Mat<2>::identity())
	//{}
	for (auto& vertex : m_vertices)
		vertex = vertex * m_model;
	m_model = math_lib::Mat<2>::identity();
}

const math_lib::Vec2 Player::fireDirection() const
{
	math_lib::Vec2 shootDir = m_vertices[1];
	math_lib::Vec2 shootDirN = shootDir * (1 / shootDir.magnitude());
	return shootDirN;
}

void Player::scale(float scalar)
{
	float matrix[2][2] = {
		{ scalar, 0 },
		{ 0, scalar }
	};
	math_lib::Mat<2> scale(matrix);
	m_model = m_model * scale;
}

void Player::rotate(float angle)
{
	angle = angle * (PI / 180);
	float matrix[2][2] = {
		{ std::cos(angle), std::sin(angle) },
		{ -std::sin(angle), std::cos(angle) }
	};
	math_lib::Mat<2> rotation(matrix);
	m_model = m_model * rotation;
}

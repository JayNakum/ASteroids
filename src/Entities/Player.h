#pragma once

#include "Entity.h"

#include "../math_lib.h"

#include <vector>

class Player : public Entity
{
public:
	float rotationSpeed = 2;

	Player();

	void draw() const override;
	void update();

	const math_lib::Vec2 fireDirection() const;

	void scale(float scalar);
	void rotate(float angle);

private:

	std::vector<math_lib::Vec2> m_vertices = {
		{  0.0,  0.0 },
		{  0.0,  1.0 },
		{  0.5, -0.1 },
		{ -0.5, -0.1 },
	};
	std::vector<unsigned int> m_indices = {
		0, 1, 2,
		0, 3, 1
	};

	math_lib::Mat<2> m_model = math_lib::Mat<2>::identity();
};
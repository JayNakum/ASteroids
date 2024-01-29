#pragma once

#include "../math_lib/math_lib.h"

class Entity
{
public:
	math_lib::Vec2 position = { 0.0f };
	virtual void draw() const = 0;
	bool destroy = false;
};

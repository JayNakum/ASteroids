#pragma once

#include <iostream>

static uint32_t PCG_Hash(uint32_t input)
{
	uint32_t state = input * 747796405u + 2891336453u;
	uint32_t word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
	return (word >> 22u) ^ word;
}

static float randomFloat(uint32_t& seed)
{
	seed = PCG_Hash(seed);
	return (float)seed / (float)std::numeric_limits<uint32_t>::max();
}

static float randomFloat(uint32_t& seed, float min, float max)
{
	seed = PCG_Hash(seed);
	return (min + (max - min)) * ((float)seed / (float)std::numeric_limits<uint32_t>::max());
}
#pragma once
#include <stdint.h>

class World;

struct Color
{
	uint8_t r, g, b;
};

class Particle
{
public:
	Color m_color;
	
	Particle(Color color);
	virtual void update(size_t xPos, size_t yPos, World& worldGrid) = 0;
};

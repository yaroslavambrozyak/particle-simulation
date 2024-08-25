#pragma once
#include <stdint.h>

struct Color
{
	uint8_t r, g, b;
};

class Particle
{
public:
	Color m_color;
public:
	Particle(Color color);
};

class EmptyParticle : public Particle
{
public:
	EmptyParticle();
};

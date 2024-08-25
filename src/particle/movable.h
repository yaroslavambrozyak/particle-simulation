#pragma once
#include "particle.h"
#include "world.h"

struct Position
{
	uint8_t x;
	uint8_t y;
};

class Movable: public Particle
{
public:
	virtual void move(World& worldGrid, Position currentPosition) = 0;
};
#pragma once
#include "particle/particle.h"
#include "world/world_grid.h"

class Sand : public Particle
{
public:
	using Particle::Particle;

	virtual void update(size_t xPos, size_t yPos, WorldGrid& worldGrid) override;
};
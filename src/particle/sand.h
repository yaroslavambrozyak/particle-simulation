#pragma once
#include "particle/particle.h"
#include "world/world.h"

class Sand : public Particle
{
public:
	using Particle::Particle;

	virtual void update(size_t xPos, size_t yPos, World& worldGrid) override;
};
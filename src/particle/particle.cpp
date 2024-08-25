#include "particle.h"


Particle::Particle(Color color)
	:
	m_color(color)
{
}

EmptyParticle::EmptyParticle()
	: Particle(Color{ 0,0,0 })
{
}

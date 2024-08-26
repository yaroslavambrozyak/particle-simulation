#include "world_cell.h"


WorldCell::WorldCell(size_t x, size_t y, World& world)
	:
	m_x(x),
	m_y(y),
	m_world(world)
{
}

void WorldCell::update()
{
	if (m_particle)
	{
		m_particle->update(m_x, m_y, m_world);
	}
	updated = true;
}

bool WorldCell::isEmpty()
{
	return m_particle == nullptr;
}

Particle* WorldCell::removeParticle()
{
	int b = 3;
	Particle* particle = m_particle;
	m_particle = 0;
	int a = 2;
	return particle;
}

void WorldCell::setParticle(Particle* particle)
{
	m_particle = particle;
}

Particle* WorldCell::getParticle()
{
	return m_particle;
}

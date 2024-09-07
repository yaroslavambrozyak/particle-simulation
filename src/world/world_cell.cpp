#include "world_cell.h"


WorldCell::WorldCell(size_t x, size_t y, WorldGrid& world)
	:
	m_x(x),
	m_y(y),
	m_worldGrid(world)
{
}

void WorldCell::update()
{
	if (m_particle)
	{
		m_particle->update(m_x, m_y, m_worldGrid);
	}
	updated = true;
}

bool WorldCell::isEmpty()
{
	return m_particle == nullptr;
}

Particle* WorldCell::removeParticle()
{
	Particle* particle = m_particle;
	m_particle = 0;
	updated = true;
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

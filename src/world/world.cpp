#include "world.h"

World::World(size_t width, size_t heigh)
	: 
	m_width(width),
	m_height(heigh)
{
	size_t lenght = width * heigh;
	m_worldGrid = new WorldCell* [lenght];

	for (auto i = 0; i < lenght; i++)
	{
		size_t pos = i / width;
		size_t x = pos;
		size_t y = static_cast<int>(i % width);
		m_worldGrid[i] = new WorldCell(x, y, *this);
	}
}

World::~World()
{
	delete[] m_worldGrid;
}

void World::addParticle(size_t x, size_t y, Particle* particle)
{
	size_t pos = getIndex(x, y);
	m_worldGrid[pos]->setParticle(particle);
	m_worldGrid[pos]->updated = true;
}

WorldCell* World::getCell(size_t x, size_t y)
{
	if (x >= m_width || y >= m_height) {
		return 0;
	}
	size_t pos = getIndex(x, y);
	return m_worldGrid[pos];
}

void World::moveParticle(size_t xFrom, size_t yFrom, size_t xTo, size_t yTo)
{
	size_t pos = getIndex(xFrom, yFrom);
	Particle* particle = m_worldGrid[pos]->removeParticle();
	addParticle(xTo, yTo, particle);
}

bool World::isCellFree(size_t x, size_t y)
{
	size_t pos = getIndex(x, y);
	if (y > 159) return false;
	return m_worldGrid[pos]->isEmpty();
}

size_t World::getIndex(size_t x, size_t y)
{
	return m_width * x + y;
}
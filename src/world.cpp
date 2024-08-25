#include "world.h"

World::World(size_t width, size_t heigh)
	: 
	m_width(width),
	m_height(heigh)
{
	size_t lenght = width * heigh;
	m_worldGrid = new int[lenght];
	m_privateGrid = new int[lenght];

	for (auto i = 0; i < lenght; i++)
	{
		m_worldGrid[i] = 0;
		m_privateGrid[i] = 0;

	}
}

World::~World()
{
	delete[] m_worldGrid;
	delete[] m_privateGrid;
}

void World::addParticle(size_t x, size_t y)
{
	size_t pos = getIndex(x, y);
	m_privateGrid[pos] = 1;
}

int World::getParticleAt(size_t x, size_t y)
{
	if (x >= m_width || y >= m_height) {
		return -1;
	}
	size_t pos = getIndex(x, y);
	return m_worldGrid[pos];
}

void World::moveParticle(size_t xFrom, size_t yFrom, size_t xTo, size_t yTo)
{
	size_t pos = getIndex(xFrom, yFrom);
	m_privateGrid[pos] = 0;
	addParticle(xTo, yTo);
}

void World::refresh()
{
	for (size_t i = 0;i < m_height * m_width; i++) {
		m_worldGrid[i] = m_privateGrid[i];
	}
}

size_t World::getIndex(size_t x, size_t y)
{
	return m_width * x + y;
}

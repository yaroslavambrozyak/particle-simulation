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
	int64_t index = getIndex(x, y);
	if (index >= 0)
	{
		m_worldGrid[index]->setParticle(particle);
	}
}

WorldCell* World::getCell(size_t x, size_t y)
{
	size_t index = getIndex(x, y);
	if (index < 0)
	{
		return nullptr;
	}

	return m_worldGrid[index];
}

void World::moveParticle(size_t xFrom, size_t yFrom, size_t xTo, size_t yTo)
{
	size_t indexFrom = getIndex(xFrom, yFrom);
	int64_t indexTo = getIndex(xTo, yTo);
	if (indexFrom >= 0 && indexTo >= 0)
	{
		Particle* particle = m_worldGrid[indexFrom]->removeParticle();
		addParticle(xTo, yTo, particle);
	}
}

bool World::isCellFree(size_t x, size_t y)
{
	int64_t index = getIndex(x, y);
	if (index < 0)
	{
		return false;
	}

	return m_worldGrid[index]->isEmpty();
}

int64_t World::getIndex(size_t x, size_t y)
{
	if (x < 0 || x >= m_width || y < 0 || y >= m_height) 
	{
		return -1;
	}
	return m_width * x + y;
}
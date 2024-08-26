#pragma once
#include "world_cell.h"

class Particle;

class World
{
public:
	World(size_t width, size_t heigh);
	~World();

	void addParticle(size_t x, size_t y, Particle* particle);
	WorldCell* getCell(size_t x, size_t y);
	void moveParticle(size_t xFrom, size_t yFrom, size_t xTo, size_t yTo);
	bool isCellFree(size_t x, size_t y);

private:
	WorldCell** m_worldGrid;
	size_t m_width;
	size_t m_height;

	size_t getIndex(size_t x, size_t y);
};
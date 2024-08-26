#pragma once
#include "world_cell.h"

class Particle;

class World
{
public:
	World(size_t width, size_t heigh);
	~World();

	/**
	 * @brief Adds a particle to a world grid
	 * If coordinates are out of bounds particle will not be added
	 * Particle lifetime will be managed by world itself
	 * @param x X coordinate
	 * @param y Y coordinate
	 * @param particle Particle pointer
	 */
	void addParticle(size_t x, size_t y, Particle* particle);
	/**
	 * @brief Returns a grid cell. 
	 * If position is out of bounds then returns null
	 * @param x X coordinate
	 * @param y Y coordinate
	 * @return world cell pointer
	 */
	WorldCell* getCell(size_t x, size_t y);
	/**
	 * @brief Moves particle from one cell to another.
	 * @param xFrom X origin
	 * @param yFrom Y origin
	 * @param xTo X target
	 * @param yTo Y target
	 */
	void moveParticle(size_t xFrom, size_t yFrom, size_t xTo, size_t yTo);
	/**
	 * @brief Check if cell contains any particle
	 * @param x X coordinate
	 * @param y Y coordinate
	 * @return true if cell does not have a particle
	 */
	bool isCellFree(size_t x, size_t y);

private:
	WorldCell** m_worldGrid;
	size_t m_width;
	size_t m_height;

	int64_t getIndex(size_t x, size_t y);
};
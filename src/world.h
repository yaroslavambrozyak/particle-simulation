#pragma once
class World
{
public:
	World(size_t width, size_t heigh);
	~World();

	void addParticle(size_t x, size_t y);
	int getParticleAt(size_t x, size_t y);
	void moveParticle(size_t xFrom, size_t yFrom, size_t xTo, size_t yTo);
	void refresh();

private:
	int* m_worldGrid;
	int* m_privateGrid;
	size_t m_width;
	size_t m_height;

	size_t getIndex(size_t x, size_t y);
};
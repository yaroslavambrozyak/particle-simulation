#pragma once
#include "stdint.h"
#include "world_grid.h"
#include <SFML/Graphics.hpp>

class Particle;

class World
{
public:
	World(uint32_t width, uint32_t height, uint8_t scale, sf::RenderWindow& window);

	void update();
	void draw();
	void addParticle(uint32_t x, uint32_t y, Particle* particle);

private:
	WorldGrid m_worldGrid;
	sf::RenderWindow& m_window;
	uint8_t m_scale;
};
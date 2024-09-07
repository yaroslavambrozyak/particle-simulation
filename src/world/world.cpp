#include "world.h"

World::World(uint32_t width, uint32_t height, uint8_t scale, sf::RenderWindow& window)
	:
	m_worldGrid(width / scale, height / scale),
	m_scale(scale),
	m_window(window)
{
}

void World::update()
{
	for (uint32_t x = 0; x < m_worldGrid.getWidth(); x++)
	{
		for (size_t y = 0; y < m_worldGrid.getHeight(); y++)
		{
			WorldCell* worldCell = m_worldGrid.getCell(x, y);
			if (!worldCell || worldCell->updated)
			{
				continue;
			}

			worldCell->update();
		}
	}
}

void World::draw()
{
	for (size_t x = 0; x < m_worldGrid.getWidth(); x++)
	{
		for (size_t y = 0; y < m_worldGrid.getHeight(); y++)
		{
			WorldCell* worldCell = m_worldGrid.getCell(x, y);

			if (worldCell && !worldCell->isEmpty())
			{
				worldCell->updated = false;
				sf::RectangleShape particleShape = sf::RectangleShape();

				Color particleColor = worldCell->getParticle()->m_color;
				sf::Color color(particleColor.r, particleColor.g, particleColor.b);

				particleShape.setFillColor(color);

				particleShape.setPosition(x * m_scale, y * m_scale);
				particleShape.setSize(sf::Vector2f(m_scale, m_scale));
				m_window.draw(particleShape);
			}
		}
	}
}

void World::addParticle(uint32_t x, uint32_t y, Particle* particle)
{
	uint32_t xGridPos = x / m_scale;
	uint32_t yGridPos = y / m_scale;
	m_worldGrid.addParticle(xGridPos, yGridPos, particle);
}

#include "simulation.h"

#include <SFML/Graphics.hpp>
#include <iostream>

Simulation::Simulation(SimulationConfig& simConfig) :
	m_simConfig(simConfig),
	window(sf::VideoMode(m_simConfig.width, m_simConfig.height), "FSand sim"),
	m_worldWidth(simConfig.width / simConfig.particleSize),
	m_worldHeight(simConfig.height / simConfig.particleSize),
	world(simConfig.width / simConfig.particleSize, simConfig.height / simConfig.particleSize)
{
	start();
}

void Simulation::start()
{
	sf::Clock clock;
	float update_freq = 0.01f;
	float update_timer = update_freq;

	while (window.isOpen())
	{
		handleInput();

		float t = clock.restart().asSeconds();
		update_timer -= t;

		if (update_timer < 0.0f) {
			update();
			update_timer = update_freq;
		}

		draw();
	}
}

void Simulation::handleInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			world.addParticle(event.mouseButton.x / 5, event.mouseButton.y / 5);
		}

	}
}

void Simulation::update()
{
	for (size_t x = 0; x < m_worldWidth; x++)
	{
		for (size_t y = 0; y < m_worldHeight; y++)
		{
			int particle = world.getParticleAt(x, y);
			if (particle == 1) {
				int particleBelow = world.getParticleAt(x, y + 1);
				if (particleBelow == 0) {
					world.moveParticle(x, y, x, y + 1);
					continue;
				}

				int particleBelowLeft = world.getParticleAt(x - 1, y + 1);
				if (particleBelowLeft == 0) {
					world.moveParticle(x, y, x - 1, y + 1);
					continue;
				}

				int particleBelowRight = world.getParticleAt(x + 1, y + 1);
				if (particleBelowRight == 0) {
					world.moveParticle(x, y, x + 1, y + 1);
					continue;
				}
			}
		}
	}

	world.refresh();
}

void Simulation::draw()
{
	window.clear();
	
	for (size_t x = 0; x < m_worldWidth; x++)
	{
		for (size_t y = 0; y < m_worldHeight; y++)
		{
			int particle = world.getParticleAt(x, y);
			if (particle == 1)
			{
				sf::RectangleShape particleShape = sf::RectangleShape();
				particleShape.setFillColor(sf::Color::White);

				particleShape.setPosition(x * m_simConfig.particleSize, y * m_simConfig.particleSize);
				particleShape.setSize(sf::Vector2f(m_simConfig.particleSize, m_simConfig.particleSize));
				window.draw(particleShape);

			}
		}
	}

	window.display();
}

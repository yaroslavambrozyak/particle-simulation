#include "simulation.h"
#include "particle/sand.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

Simulation::Simulation(SimulationConfig& simConfig) :
	m_simConfig(simConfig),
	m_window(sf::VideoMode(m_simConfig.width, m_simConfig.height), "FSand sim"),
	m_worldWidth(simConfig.width / simConfig.particleSize),
	m_worldHeight(simConfig.height / simConfig.particleSize),
	m_world(simConfig.width / simConfig.particleSize, simConfig.height / simConfig.particleSize)
{
	start();
	m_window.setFramerateLimit(120);
}

void Simulation::start()
{
	sf::Clock clock;
	float update_freq = 0.01f;
	float update_timer = update_freq;

	while (m_window.isOpen())
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
	static bool leftMouseKeyPressed;

	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				leftMouseKeyPressed = true;
			}
		}
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				leftMouseKeyPressed = false;
			}
		}	

	}

	if (leftMouseKeyPressed)
	{
		auto mousePos = sf::Mouse::getPosition(m_window);
		m_world.addParticle(mousePos.x / m_simConfig.particleSize, mousePos.y / m_simConfig.particleSize, new Sand(Color{ 255, 255, 255 }));
	}
}

void Simulation::update()
{
	for (size_t x = 0; x < m_worldWidth; x++)
	{
		for (size_t y = 0; y < m_worldHeight; y++)
		{
			WorldCell* worldCell = m_world.getCell(x, y);
			if (!worldCell || worldCell->updated)
			{
				continue;
			}

			worldCell->update();
		}
	}

}

void Simulation::draw()
{
	m_window.clear();
	
	for (size_t x = 0; x < m_worldWidth; x++)
	{
		for (size_t y = 0; y < m_worldHeight; y++)
		{
			WorldCell* worldCell = m_world.getCell(x, y);
			if (worldCell && !worldCell->isEmpty())
			{
				worldCell->updated = false;
				sf::RectangleShape particleShape = sf::RectangleShape();
				particleShape.setFillColor(sf::Color::White);

				particleShape.setPosition(x * m_simConfig.particleSize, y * m_simConfig.particleSize);
				particleShape.setSize(sf::Vector2f(m_simConfig.particleSize, m_simConfig.particleSize));
				m_window.draw(particleShape);

			}
		}
	}

	m_editor.draw(m_window);

	m_window.display();
}

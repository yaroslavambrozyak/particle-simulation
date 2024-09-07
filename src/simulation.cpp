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
	m_world(simConfig.width, simConfig.height, simConfig.particleSize, m_window),
	m_editor(m_world, m_window)
{
	m_window.setFramerateLimit(120);
	start();
}

void Simulation::start()
{
	sf::Clock clock;
	float update_freq = 0.01f;
	float update_timer = update_freq;

	while (m_window.isOpen())
	{
		float t = clock.restart().asSeconds();
		update_timer -= t;

		if (update_timer < 0.0f) {
			update();
			update_timer = update_freq;
		}

		draw();
	}
}

void Simulation::update()
{
	m_world.update();
	m_editor.update();
}

void Simulation::draw()
{
	m_window.clear();
	
	m_editor.draw();
	m_world.draw();

	m_window.display();
}

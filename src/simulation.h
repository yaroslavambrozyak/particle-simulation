#pragma once
#include <SFML/Graphics.hpp>
#include <world.h>

struct SimulationConfig 
{
	size_t width;
	size_t height;
	size_t particleSize;
};

class Simulation 
{
public:
	Simulation(SimulationConfig& simConfig);
private:
	SimulationConfig& m_simConfig;
	sf::RenderWindow window;
	World world;
	uint32_t m_worldWidth;
	uint32_t m_worldHeight;

	void start();
	void handleInput();
	void update();
	void draw();
};
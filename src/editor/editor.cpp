#include "editor.h"
#include "world/world.h"
#include "particle/sand.h"




Editor::Editor(World& world, sf::RenderWindow& window)
	:
	m_world(world),
	m_window(window)
{

}

void Editor::update()
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
		else if (event.type == sf::Event::MouseWheelScrolled)
		{
			auto delta = event.mouseWheelScroll.delta;
			m_brushSize += delta;
		}

	}

	if (leftMouseKeyPressed)
	{
		auto mousePos = sf::Mouse::getPosition(m_window);
		spawnParticle(mousePos.x, mousePos.y);
	}
}

void Editor::draw()
{
	sf::CircleShape circle;
	circle.setRadius(m_brushSize);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(1);
	circle.setFillColor(sf::Color(0, 0, 0, 0));
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	auto mousePos = sf::Mouse::getPosition(m_window);

	circle.setPosition(mousePos.x, mousePos.y);
	
	m_window.draw(circle);
}

void Editor::spawnParticle(uint32_t x, uint32_t y)
{
	uint8_t brushRadius = m_brushSize;

	uint8_t particleSize = brushRadius * brushRadius;

	while (particleSize > 0)
	{
		auto theta = 2 * 3.1415 * (((double)rand() / (RAND_MAX)) + 1);
		uint8_t randRadius = std::rand() % (brushRadius + 1);
		uint32_t xP = x + randRadius * cos(theta);
		uint32_t yP = y + randRadius * sin(theta);
		m_world.addParticle(xP, yP, new Sand(Color{ 216, 197, 133 }));
		particleSize--;
	}
}

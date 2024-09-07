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
		m_world.addParticle(mousePos.x, mousePos.y, new Sand(Color{ 255, 255, 255 }));
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

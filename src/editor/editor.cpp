#include "editor.h"

void Editor::draw(sf::RenderWindow& window)
{
	sf::CircleShape circle;
	circle.setRadius(m_brushSize);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(1);
	circle.setFillColor(sf::Color(0, 0, 0, 0));
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	auto mousePos = sf::Mouse::getPosition(window);

	circle.setPosition(mousePos.x, mousePos.y);
	
	window.draw(circle);
}

void Editor::changeBrushSize(uint8_t step)
{
	m_brushSize += step;
}
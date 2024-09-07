#include <SFML/Graphics.hpp>
#include "world/world.h"

class Editor
{
public:
	Editor(World& world, sf::RenderWindow& window);

	void draw();
	void update();

private:
	World& m_world;
	sf::RenderWindow& m_window;
	uint8_t m_brushSize = 5;
};
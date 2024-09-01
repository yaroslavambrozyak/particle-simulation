#include <SFML/Graphics.hpp>
#include <stdint.h>

class Editor
{
public:
	void draw(sf::RenderWindow& window);

	void setBrushSize(uint8_t brushRadius);

private:
	uint8_t m_brushSize = 25;
};
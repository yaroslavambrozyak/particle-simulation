#include <SFML/Graphics.hpp>


class Editor
{
public:
	void draw(sf::RenderWindow& window);

	void changeBrushSize(uint8_t step);

private:
	uint8_t m_brushSize = 5;
};
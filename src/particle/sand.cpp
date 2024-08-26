#include "sand.h"

void Sand::update(size_t xPos, size_t yPos, World& worldGrid)
{
	if (worldGrid.isCellFree(xPos, yPos + 1))
	{
		worldGrid.moveParticle(xPos, yPos, xPos, yPos + 1);
	}
}
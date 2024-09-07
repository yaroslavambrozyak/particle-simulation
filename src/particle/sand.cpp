#include "sand.h"

void Sand::update(size_t xPos, size_t yPos, WorldGrid& worldGrid)
{
	if (worldGrid.isCellFree(xPos, yPos + 1))
	{
		worldGrid.moveParticle(xPos, yPos, xPos, yPos + 1);
	}
	else if (worldGrid.isCellFree(xPos + 1, yPos + 1))
	{
		worldGrid.moveParticle(xPos, yPos, xPos + 1, yPos + 1);
	}
	else if (worldGrid.isCellFree(xPos - 1, yPos + 1))
	{
		worldGrid.moveParticle(xPos, yPos, xPos - 1, yPos + 1);
	}
}
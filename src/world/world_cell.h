#include "particle/particle.h"

class World;

class WorldCell
{
public:
	WorldCell(size_t x, size_t y, World& world);

	bool updated = false;

	void update();
	bool isEmpty();

	Particle* removeParticle();
	void setParticle(Particle* particle);
	Particle* getParticle();

private:
	size_t m_x;
	size_t m_y;
	World& m_world;
	Particle* m_particle = nullptr;

};
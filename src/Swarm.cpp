#include "Swarm.h"

namespace dana {
	Swarm::Swarm() :

		//initializing array of particles
		m_particles{ new Particle[N_PARTICLES] }
	{}

	Swarm::~Swarm() {
		
		//freeing memory cuz why not
		delete[] m_particles;
	}
}
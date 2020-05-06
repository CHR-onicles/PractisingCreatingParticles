#include "Swarm.h"

namespace dana {
	Swarm::Swarm() :

		//initializing array of particles
		m_particles{ new Particle[N_PARTICLES] }
	{}

	void Swarm::update() {
		//apply motion to every particle
		for (size_t i{ 0 }; i < N_PARTICLES; ++i) {
			m_particles[i].update();
		}
	}

	Swarm::~Swarm() {
		
		//freeing memory cuz why not
		delete[] m_particles;
	}
}
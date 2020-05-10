#pragma once
#include "Particle.h"

namespace dana {
	class Swarm{
	private:
		//pointer to a collection of particles
		Particle* m_particles;
	public:
		Swarm();
		~Swarm();

		//number of total particles
		const static int N_PARTICLES = 5000;

		//methods
		const Particle* const getParticles()const  { return m_particles; } //typing all those consts was just satisfying XD

		void update();
	};
}
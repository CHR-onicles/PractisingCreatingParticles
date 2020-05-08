#include "Particle.h"

namespace dana {
	Particle::Particle():

		//using random values to generate doubles for coordinates of x and y for pixels.
		//mapped the values to window size in main
		//also, used doubles for variety in coords generated
		m_x{ (2.0 * rand()) / RAND_MAX},
		m_y{ (2.0 * rand()) / RAND_MAX }
	{}
		
}
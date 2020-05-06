#include "Particle.h"

namespace dana {
	Particle::Particle():

		//using random values to generate doubles for coordinates of x and y for pixels.
		//mapped the values to window size in main
		//also, used doubles for variety in coords generated
		m_x{ (2.0 * rand()) / RAND_MAX},
		m_y{ (2.0 * rand()) / RAND_MAX },

		//random values for particles to move randomly, 0.0001 is the speed constant ie how fast they move
		m_xspeed{ 0.001 * (((2.0 * rand()) / RAND_MAX) - 1) },
		m_yspeed{ 0.001 * (((2.0 * rand()) / RAND_MAX) - 1) }		
	{}

	void Particle::update() {
		//give the particles motion
		m_x += m_xspeed;
		m_y += m_yspeed;

		//check to make sure particles dont move out of screen
		if (m_x <= 0.0 || m_x >= 2.0)
			m_xspeed = -m_xspeed;	//reverse direction if going out of screen
		if (m_y <= 0.0 || m_y >= 2.0)
			m_yspeed = -m_yspeed;
	}

		
}
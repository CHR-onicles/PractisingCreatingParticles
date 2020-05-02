#pragma once
#include <cstdlib>

namespace dana {

	struct Particle{
		//used struct instead of class for member variables to be accessed directly for the sake of efficiency
		//as is done in actual games.
		double m_x;
		double m_y;

		Particle();

	};
}
#pragma once
#include <SDL2/SDL.h>
#include <cstdlib>
#include "Particle.h"

namespace dana {
	class Screen {
	private:
		//member variables hence "m_" preceeding them
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		Uint32* m_buffer;

	public:
		Screen();

		//window dimensions
		const static int WINDOW_WIDTH = 800;
		const static int WINDOW_HEIGHT = 600;

		//methods
		bool init();
		bool processEvents();
		void close();
		void updateScreen();
		void setPixelColor(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

	};

}
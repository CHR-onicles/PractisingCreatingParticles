#include "Screen.h"

namespace dana {
	Screen::Screen()
		:m_window{NULL}, m_renderer{ NULL },m_texture{NULL},m_buffer{NULL}{}

	bool Screen::init() {

		//creating window
		m_window = SDL_CreateWindow("STAR FIELD",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_window == NULL) {
			SDL_Quit();
			return false;
		}

		//creating renderer
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		if (m_renderer == NULL) {
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		//creating texture
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
			WINDOW_WIDTH, WINDOW_HEIGHT);
		if (m_texture == NULL) {
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		//creating space for buffer and setting to 32bit unsigned int to hold info of pixels
		m_buffer = new Uint32[WINDOW_WIDTH * WINDOW_HEIGHT];

		memset(m_buffer, 0x0, WINDOW_WIDTH * sizeof(Uint32) * WINDOW_HEIGHT); //set all pixels to black initially

		return true;
	}

	//to clear screen right after change in particles to prevent trail in colors while animating
	void Screen::clearScreen() {
		memset(m_buffer, 0x0, WINDOW_WIDTH * sizeof(Uint32) * WINDOW_HEIGHT);
	}

	bool Screen::processEvents() {

		//event to check if user closed window
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return false;
			}
		}
		return true;
	}

	void Screen::updateScreen() {

		//update window while game loop runs
		SDL_UpdateTexture(m_texture, NULL, m_buffer, WINDOW_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}

	void Screen::setPixelColor(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

		//check and discard pixels plotted off the window
		if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT) return;

		//using bit shifting to put all 8 bit RBGA values into 1 color value of 32bit
		Uint32 color = 0;
		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0XFF;	//setting Alpha to opaque (opacity value)

		m_buffer[(y * WINDOW_WIDTH) + x] = color;	//setting the particular pixel in the buffer to the color
	}

	void Screen::close() {

		//freeing resources
		delete[] m_buffer;
		SDL_DestroyTexture(m_texture);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace dana;   //used this namespace to avoid name collisions

int main(int agrc, char* args[]){
    srand(time(NULL)); //seeding random value for plotting of particles/pixels

    //initialize screen and make sure all dependencies were initialized correctly
    Screen screen;
    if (!screen.init())
        cerr << "Error initializing SDL" << endl; 

    //initialize swarm of particles
    Swarm swarm;
    const Particle* const pParticle = swarm.getParticles();

    //Game loop
    while (true) {

        //Draw particles

        int elapsed = SDL_GetTicks();   //get number of ms since window was created
        swarm.update();
        screen.clearScreen();

        //gradually increase RBG values from 0 to 255 for pixels
        //also, used different const values ie 0.0001, 0.0002, 0.0003 for the colors to be slightly out of sync
        //so that we have that smooth transition effect for the colors
        //"1 + " to eliminate negative values ie lower bound is 0
        //"(elapsed * 0.0001)" to greatly reduce the change in values when loop runs...so that it increases slowly
        //" * 127.5" to set the upperbound which is 255... so we multiply by half of actual upperbound

        unsigned char red = static_cast<unsigned char>(( 1  + sin(elapsed * 0.0001)) * 127.5);
        unsigned char green = static_cast<unsigned char>(( 1  + cos(elapsed * 0.0002)) * 127.5);
        unsigned char blue = static_cast<unsigned char>((1 + sin(elapsed * 0.0003)) * 127.5);
               
        //the loop that does the magic :)
        for (int i{ 0 }; i < Swarm::N_PARTICLES; ++i) {

            //mapping particle coords to screen
            int x = pParticle[i].m_x * Screen::WINDOW_WIDTH / 2;
            int y = pParticle[i].m_y * Screen::WINDOW_HEIGHT / 2;
            

            screen.setPixelColor(x, y, red, green, blue);    //setting color of individual pixels        
        }

        //Update screen
        screen.updateScreen();

        //process events
        if (!screen.processEvents()) break;
    }
    
    //freeing resources, because that's what heros do XD
    screen.close();
    return 0;
}
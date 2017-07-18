#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
//mai jos includem clasele
#include"Display.h"

//final

std::string TITLE="The Maze";
Display display(TITLE);
SDL_Event ev;
bool running(true);




int main(int argc, char*argv[])
{
    while(running){
        SDL_PollEvent(&ev);
        if(ev.key.keysym.sym==SDLK_ESCAPE)
            running=false;
        display.render();
    }

    return 0;
}

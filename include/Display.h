#ifndef DISPLAY_H
#define DISPLAY_H
#include<string>
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

class Display
{
    public:
        Display(std::string);//Initializare
        ~Display(){
            SDL_DestroyWindow(_window);
            SDL_Quit();
            IMG_Quit();
        }
        void render();//Afisare imagini
        int getWidth();//Getter
        int getHeight();//'-'
        std::string getTitle();//'-'

    private:
        int _width=NULL;//latime ecran
        int _height=NULL;//inaltime ecran
        std::string _title="Error-unselected";//titlu
        SDL_Window*_window=nullptr;
        SDL_Renderer*_renderer=nullptr;
        SDL_DisplayMode _disp;
};

#endif // DISPLAY_H

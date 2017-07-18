#include "Display.h"

Display::Display(std::string title)
{
    //Initializare

    int flag=SDL_Init(SDL_INIT_EVERYTHING);
    if(flag<0){
        std::cerr<<"Initializarea SDL a esuat "<<SDL_GetError()<<std::endl;
    }
    else{
        if(SDL_GetDesktopDisplayMode(0,&_disp)!=0)
                std::cerr<<"Get Desktop Display Mode Failed "<<SDL_GetError()<<std::endl;
        else{
            _width=_disp.w;
            _height=_disp.h;
            _title=title;
            std::cout<<_width<<" "<<_height<<std::endl;
                }

        int flags=IMG_INIT_JPG|IMG_INIT_PNG;
        int init=IMG_Init(flags);
        if((init%flags)!=flags&&false){
            std::cerr<<"Initialiazarea SDL_image a esuat "<<IMG_GetError()<<std::endl;
        }
        else{
            _window=SDL_CreateWindow(_title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,_width,_height,SDL_WINDOW_SHOWN);
            if(_window==nullptr){
                std::cerr<<"Fereastra nu a fost creata--> EROARE "<<SDL_GetError()<<std::endl;
            }
            else{
                //Alte initializari
            }
    }

}
}


int Display::getHeight(){
    return _height;
}

int Display::getWidth(){
    return _width;
}

std::string Display::getTitle(){
    return _title;
}

void Display::render(){
    //Aici se pun imaginile pentru afisare

}


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
                }
            if(TTF_Init()==-1){
                std::cerr<<"True Type Fonts failed to initialize "<<TTF_GetError()<<std::endl;
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
                _renderer=SDL_CreateRenderer(_window,-1,SDL_RENDERER_ACCELERATED);
                if(_renderer==nullptr){
                    std::cerr<<"Renderer was not created "<<SDL_GetError()<<std::endl;
                }
            }
    }

}

    _menu=new Menu(_renderer,_width,_height);

    _mapMaker=new MapMaker(_renderer,_width,_height);
    _gameSelection=new GameSelection(_renderer,_width,_height);
    _game=new Game(_renderer,_width,_height);
    _curScreen=_menu;
    _screenState=SCREEN_STATE::MenuScreen;

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

void Display::render(SDL_Event& ev){
    //Aici se pun imaginile pentru afisare
    SDL_RenderClear(_renderer);
    _curScreen->show(_renderer);
    _curScreen->renderGrid();

    SDL_RenderPresent(_renderer);

    switch(_screenState){

    case SCREEN_STATE::MenuScreen:
        if(_curScreen->gamePressed(ev)){
            _curScreen=_gameSelection;
            _screenState=SCREEN_STATE::GameSelectionScreen;
            SDL_Delay(250);
        }
        else if(_curScreen->mapcrPressed(ev)){
            delete _mapMaker;
            _mapMaker=nullptr;
            _mapMaker=new MapMaker(_renderer,_width,_height);
            _curScreen=_mapMaker;
            _screenState=SCREEN_STATE::MapMakerScreen;
            _curScreen->createMap();
            SDL_Delay(250);

        }

        break;

    case SCREEN_STATE::GameScreen:
        _curScreen->runMap(ev);
        //cout<<"Ceva";

        break;
    case SCREEN_STATE::MapMakerScreen:
            _curScreen->runMap(ev);
            if(ev.type==SDL_KEYDOWN){
                if(ev.key.keysym.sym==SDLK_s){
                    _curScreen->save("Map.tmmap");
                    SDL_Delay(250);
                }
                if(ev.key.keysym.sym==SDLK_BACKSPACE){
                    _curScreen->DeleteAll();
                    _curScreen=_menu;
                    _screenState=SCREEN_STATE::MenuScreen;
                }
            }
        break;
    case SCREEN_STATE::GameSelectionScreen:
        _curScreen->runMap(ev);
        if(ev.type==SDL_KEYDOWN){
            if(ev.key.keysym.sym==SDLK_BACKSPACE){
                    _curScreen=_menu;
                    _screenState=SCREEN_STATE::MenuScreen;
                }
        }
        if(_curScreen->gamePressed(ev)){
            _curScreen=_game;
            _screenState=SCREEN_STATE::GameScreen;
            SDL_Delay(250);
        }
        break;

    }

}


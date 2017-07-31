#ifndef GAME_H
#define GAME_H

#include <Screen.h>
#include <SDL.h>
#include <string>
#include <vector>
#include "Map.h"
#include "Block.h"
#include <fstream>
#include "Animation.h"

using namespace std;

class Game : public Screen
{
    public:
        Game(SDL_Renderer*ren,int ScreenWidth,int ScreenHeight);
        ~Game();

        bool gamePressed(SDL_Event&ev){return false;}
        bool mapcrPressed(SDL_Event&ev){return false;}
        void createMap(){ }
        void renderGrid(){ }
        void runMap(SDL_Event&ev);
        void save(string filepath){ }
    protected:
        vector<string>types;
        SDL_Renderer*_ren;
        int _tileW;
        int _tileH;
        int _numBlocksOnScreen=10;
        int _screenWidth;
        int _screenHeight;
        float _rw;
        float _rh;
        void LoadCurMap();
        void update_size();
        Map _map;
        COORDONATE Square[300][300];
        COORDONATE SquareOf(int x,int y);
        char convert(string type);
        int convert_back(char code);
        void LoadTypes();

        Animation *test;
        int tx=600;
        int ty=900;
        int tw=101;
        int th=77;
        int its=10;
        bool show=true;

};

#endif // GAME_H

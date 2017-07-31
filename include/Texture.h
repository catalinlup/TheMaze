#ifndef TEXTURE_H
#define TEXTURE_H
#include<string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
using namespace std;

class Texture
{
    public:
        Texture();
        void loadTexture(string filepath,int width,int height,int x,int y,SDL_Renderer*ren);
        void displayTexture(int width,int height,int x,int y,SDL_Renderer*ren);
        ~Texture();
    private:
        SDL_Rect _srcRect;
        SDL_Texture* _texture;
        string _filepath;
};

#endif // TEXTURE_H

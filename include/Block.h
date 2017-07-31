#ifndef BLOCK_H
#define BLOCK_H
#include <SDL.h>
#include <string>
#include <Texture.h>


class Block
{
    public:
        Block(string type,string format,SDL_Renderer*ren);
        Texture* getTexture();
        string getType();
        ~Block();
    private:
        Texture*_blockTexture;
        SDL_Renderer*_ren;
        string _type;
        string _format;
        string _filepath="res/blocks/";
        const int _width=30;
        const int _height=30;

};

#endif // BLOCK_H

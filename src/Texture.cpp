#include "Texture.h"

Texture::Texture()
{
    //ctor
}

Texture::~Texture()
{
    //dtor
}

void Texture::loadTexture(string filepath,int width,int height,int x,int y,SDL_Renderer*ren){
    _filepath=filepath;
    _srcRect.w=width;
    _srcRect.h=height;
    _srcRect.x=x;
    _srcRect.y=y;
    SDL_Surface*surf=nullptr;
    surf=IMG_Load(_filepath.c_str());
    SDL_SetColorKey(surf,SDL_TRUE,SDL_MapRGB(surf->format,255,255,255));
    if(surf==nullptr){
        std::cerr<<"Image at location "+_filepath+" unable to load "<<IMG_GetError()<<std::endl;
    }
    _texture=nullptr;
    _texture=SDL_CreateTextureFromSurface(ren,surf);
    if(_texture==nullptr){
        std::cerr<<"Texture at location "+_filepath+" unable to load "<<SDL_GetError()<<std::endl;
    }
    SDL_FreeSurface(surf);

}

void Texture::displayTexture(int width,int height,int x,int y,SDL_Renderer*ren){
    SDL_Rect dest;
    dest.w=width;
    dest.h=height;
    dest.x=x;
    dest.y=y;
     //std::cout<<width<<" "<<height<<" "<<x<<" "<<y<<std::endl;
     //std::cout<<_texture<<std::endl;
    SDL_RenderCopy(ren,_texture,&_srcRect,&dest);
}

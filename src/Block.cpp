#include "Block.h"

Block::Block(string type,string format,SDL_Renderer*ren)
{
    //ctor
    _ren=ren;
    _type=type;
    _format=format;
    string fullfile=_filepath+_type+"."+_format;
    _blockTexture=new Texture();
    _blockTexture->loadTexture(fullfile.c_str(),_width,_height,0,0,_ren);
}

Texture* Block::getTexture(){
    return _blockTexture;
}

string Block::getType(){
    return _type;
}

Block::~Block()
{
    //dtor
}

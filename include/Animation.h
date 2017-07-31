#ifndef ANIMATION_H
#define ANIMATION_H

#include<SDL.h>
#include"Texture.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;


class Animation
{
    public:
        Animation(string folder,string filename,int x,int y,int w,int h,SDL_Renderer*ren,int num=0,int ind=-1);
        void run(int iterations_per_frame);
        void display(int x,int y,int w,int h);
        ~Animation();

    protected:
    private:
        vector<Texture*> _frames;
        vector<string> _frameNames;
        string _folder;
        string _filename;
        Texture* cur_texture;
        int cur_frame=0;
        int _AX=0;
        int _AY=0;
        int _AW=0;
        int _AH=0;
        int _num;
        SDL_Renderer*_ren;

};

#endif // ANIMATION_H

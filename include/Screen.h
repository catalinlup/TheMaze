#ifndef SCREEN_H
#define SCREEN_H
#include<vector>
#include"DisplayObject.h"
#include <iostream>
#include "Button.h"
#include <string>
#include "Animation.h"
using namespace std;

struct COORDONATE{
    int x;
    int y;

};


struct prop{
int *x;
int *y;
int *w;
int *h;
int *iterations;
bool *show;
void operator=(prop other){
    x=other.x;
    y=other.y;
    w=other.w;
    h=other.h;
    iterations=other.iterations;
    show=other.show;

}


};

class Screen
{
    public:
        Screen();
    vector<Texture*> objects;
    vector<Button*> butts;
    vector<prop> coords;
    vector<Animation*>anims;
    vector<prop> anims_coords;
    DisplayObject* vec[50];

    void add(Texture* dis,int*x,int *y,int*w,int*h){
        objects.push_back(dis);
        prop Prop;
        Prop.x=x; Prop.y=y; Prop.w=w; Prop.h=h;
        coords.push_back(Prop);
    }
    void addAnimation(Animation*an,int*x,int*y,int*w,int*h,int*iterations,bool*show){
        anims.push_back(an);
        prop Prop;
        Prop.x=x; Prop.y=y; Prop.w=w; Prop.h=h; Prop.iterations=iterations; Prop.show=show;
        anims_coords.push_back(Prop);
    }
    void addButt(Button*butt){
        butts.push_back(butt);
    }
    void DeleteAll(){
        while(objects.empty()==false)
            objects.pop_back();
        while(coords.empty()==false)
            coords.pop_back();
    }
    prop undoTexture(){
        prop rasp=coords[coords.size()-1];
        if(objects.empty()==false&&coords.empty()==false){
            objects.pop_back();
            coords.pop_back();
        }
        return rasp;
    }
    void show(SDL_Renderer*ren){
        for(int i=0;i<objects.size();i++){
            int *x,*y,*w,*h;
            x=coords[i].x;
            y=coords[i].y;
            w=coords[i].w;
            h=coords[i].h;

            if(game){

                if(*x-*camX>=_ScrScreenWidth/2-_ScrScreenHeight/2&&*x-*camX<_ScrScreenWidth/2+_ScrScreenHeight/2){
                    objects[i]->displayTexture(*w,*h,*x-*camX,*y-*camY,ren);
                    //cout<<*x<<" "<<*y<<" "<<*w<<" "<<*h<<endl;
                }
            }
            else{
                objects[i]->displayTexture(*w,*h,*x-*camX,*y-*camY,ren);

            }
        }
        for(int i=0;i<butts.size();i++){
            butts[i]->display(ren);
        }
        for(int i=0;i<anims.size();i++){
            int *x,*y,*w,*h,*iterations;
            bool*show;
            x=anims_coords[i].x; y=anims_coords[i].y; w=anims_coords[i].w; h=anims_coords[i].h;
            iterations=anims_coords[i].iterations;
            show=anims_coords[i].show;
            if((*show)==true&&*x-*camX>=_ScrScreenWidth/2-_ScrScreenHeight/2&&*x-*camX<_ScrScreenWidth/2+_ScrScreenHeight/2){
                anims[i]->run(*iterations);
                anims[i]->display(*x-*camX,*y-*camY,*w,*h);
            }

        }

    }


    int*camX;
    int*camY;
    bool game=false;
    int _ScrScreenWidth=0;
    int _ScrScreenHeight=0;

    virtual bool gamePressed(SDL_Event& ev)=0;
    virtual bool mapcrPressed(SDL_Event& ev)=0;
    virtual void createMap()=0;
    virtual void renderGrid()=0;
    virtual void runMap(SDL_Event&ev)=0;
    virtual void save(string filepath)=0;
    protected:
        const int RefWidth=1980;
        const int RefHeight=1080;

    private:


};

#endif // SCREEN_H

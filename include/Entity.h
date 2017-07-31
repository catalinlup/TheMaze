#ifndef ENTITY_H
#define ENTITY_H
#include "Animation.h"
#include "Screen.h"
#include <vector>
using namespace std;


class Entity
{
    public:
        Entity();
        ~Entity();
        void setX(int x);
        void setY(int y);
        void setW(int w);
        void setH(int h);
        void addAnimation(Animation*anim,bool*show,int* iterations);
        void LoadAnimations(Screen*screen);
        vector<Animation*> animations;
        vector<bool*> shows;
        vector<int*> iterations;
        int _x;
        int _y;
        int _w;
        int _h;

    protected:

        bool isOnMap=false;
        bool isInInventory=false;



};

#endif // ENTITY_H

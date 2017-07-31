#include "Entity.h"

Entity::Entity()
{
    //ctor
}

Entity::~Entity()
{
    //dtor
}

void Entity::setX(int x){
    _x=x;
}
void Entity::setY(int y){
    _y=y;
}
void Entity::setH(int h){
    _h=h;
}
void Entity::setW(int w){
    _w=w;
}
void Entity::addAnimation(Animation*anim,bool* show,int*iteration){
    animations.push_back(anim);
    shows.push_back(show);
    iterations.push_back(iteration);
}
void Entity::LoadAnimations(Screen*screen){
    for(int i=0;i<animations.size();i++){
        screen->addAnimation(animations[i],&_x,&_y,&_w,&_h,iterations[i],shows[i]);
    }
}

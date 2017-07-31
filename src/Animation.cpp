#include "Animation.h"

Animation::Animation(string folder,string filename,int x,int y,int w,int h,SDL_Renderer*ren,int num,int ind)
{
    _folder=folder;
    _filename=filename;
    _AX=x;
    _AY=y;
    _AW=w;
    _AH=h;
    _ren=ren;
    string fpath=_folder+_filename;
    if(num==0){
       ifstream in(fpath);
       string line;
       while(getline(in,line)){
            _frameNames.push_back(line);
       }
       for(int i=0;i<_frameNames.size();i++){
            Texture*txt=new Texture();
            txt->loadTexture(_frameNames[i],_AW,_AH,_AX,_AY,_ren);
            _frames.push_back(txt);
       }
       _num=_frameNames.size();
    }
    else{
        _num=num-ind+1;
        for(int i=ind;i<=num;i++){
            string pth=fpath;
            int k=i;
            string num;
            int num_cif(0);
            while(k>0){
                num.push_back(k%10+'0');
                k/=10;
                num_cif++;
            }
            string num2;
            for(int j=num.size()-1;j>=0;j--)
                num2.push_back(num[j]);
            num=num2;
            for(int j=0;j<3-num_cif;j++)
                pth+="0";
            pth=pth+num+".png";
            _frameNames.push_back(pth);
            Texture*txt=new Texture();
            txt->loadTexture(pth,_AW,_AH,_AX,_AY,_ren);
            _frames.push_back(txt);
        }
    }
    cur_texture=_frames[0];
}

void Animation::run(int iteration_prt_frame){
    static int Iterator=0;
    cur_texture=_frames[cur_frame];
    if(Iterator==iteration_prt_frame){
        if(cur_frame>=_num-1)
            cur_frame=0;
        else
            cur_frame++;
        Iterator=0;
    }
    Iterator++;
}

void Animation::display(int x,int y,int w,int h){
    cur_texture->displayTexture(w,h,x,y,_ren);
}

Animation::~Animation()
{
    //dtor
}

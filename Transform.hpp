#pragma once


#include <SDL.h>

class Transform {
public:
//=========POSITION===========
    int x, y;
    int zrot;

//=========int scale===========
    int x_sc,y_sc;


    Transform(int _x , int _y );

    SDL_Rect* ToScreenPosition();

    void translate(int _x = 0, int _y = 0);
};

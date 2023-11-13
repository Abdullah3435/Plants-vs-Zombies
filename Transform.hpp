#pragma once


#include <SDL.h>

class Transform {
public:
    int x, y;
    int zrot;

    Transform(int _x , int _y );

    SDL_Rect* ToScreenPosition();

    void translate(int _x = 0, int _y = 0);
};

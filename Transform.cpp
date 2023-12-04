#pragma once
#include "Transform.hpp"

Transform::Transform(int _x = 0, int _y = 0) {

    x = _x;
    y = _y;
    zrot = 0;
    x_sc = 1;
    y_sc = 1;
    xx =  100;
    yy =  100;
}


SDL_Rect* Transform::ToScreenPosition() {
    SDL_Rect* screenpos = new SDL_Rect{x-(xx*x_sc/2), y-(yy*y_sc/2), xx*x_sc, yy*y_sc};
    return screenpos;
}

void Transform::translate(int _x, int _y) {
    x += _x;
    y += _y;
}

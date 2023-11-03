#pragma once
#include "Transform.hpp"

Transform::Transform(int _x, int _y) {
    x = _x;
    y = _y;
    zrot = 0;
}

SDL_Rect* Transform::ToScreenPosition() {
    SDL_Rect* screenpos = new SDL_Rect{ x, y, 100, 100 };
    return screenpos;
}

void Transform::translate(int _x, int _y) {
    x += _x;
    y += _y;
}

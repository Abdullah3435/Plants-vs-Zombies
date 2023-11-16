#pragma once
#include "Transform.hpp"

Transform::Transform(int _x = 0, int _y = 0) {
    x = _x;
    y = _y;
    zrot = 0;
}

SDL_Rect* Transform::ToScreenPosition() {
    SDL_Rect* screenpos = new SDL_Rect{ x-50, y-50, 300, 300};
    return screenpos;
}

void Transform::translate(int _x, int _y) {
    x += _x;
    y += _y;
}

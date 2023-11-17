#include "Sprite.hpp"

Sprite::Sprite(SDL_Texture* tex, SDL_Rect target, SDL_Renderer* ren)
    : texture(tex), targetTexture(target), renderer(ren) {rows=1;cols=1;}

Sprite::Sprite(SDL_Texture* tex, SDL_Rect target, SDL_Renderer* ren,int _rows,int _cols)
    : texture(tex), targetTexture(target), renderer(ren) {rows=_rows;cols=_rows;}

void Sprite::render(SDL_Rect &targetpoint) {
    SDL_RenderCopy(renderer, texture, &targetTexture, &targetpoint);
}
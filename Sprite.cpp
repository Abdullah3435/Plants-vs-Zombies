#include "Sprite.hpp"

//default constructor
Sprite::Sprite(SDL_Texture* tex, SDL_Rect target, SDL_Renderer* ren)
    : texture(tex), targetTexture(target), renderer(ren) {rows=1;cols=1;}

//for Sprite class with custom rows and columns
Sprite::Sprite(SDL_Texture* tex, SDL_Rect target, SDL_Renderer* ren,int _rows,int _cols)
    : texture(tex), targetTexture(target), renderer(ren) {rows=_rows;cols=_rows;}

// Method to render the sprite on the screen at a specified target position
void Sprite::render(SDL_Rect &targetpoint) {
    // Copy the texture onto the renderer at the specified target position
    SDL_RenderCopy(renderer, texture, &targetTexture, &targetpoint);
}
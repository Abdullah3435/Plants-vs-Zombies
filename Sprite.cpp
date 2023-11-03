#include "Sprite.hpp"

Sprite::Sprite(SDL_Texture* tex, SDL_Rect target, SDL_Renderer* ren)
    : texture(tex), targetTexture(target), renderer(ren) {}

void Sprite::render() {
    SDL_RenderCopy(renderer, texture, nullptr, &targetTexture);
}
#pragma once
#include "GameObject.hpp"
#include <iostream>

GameObject::GameObject(int x, int y) {
    transform = new Transform(x, y);
}

void GameObject::SetSprite(SDL_Texture* tex, SDL_Renderer* sourcerenderer)
{
    sprite =  new Sprite(tex , SDL_Rect{ 10, 10, 350, 350 },sourcerenderer);
}

Transform* GameObject::Getposition() {
    return transform;
}

SDL_Texture* GameObject::loadTexture(std::string path) {
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        newTexture = SDL_CreateTextureFromSurface(sprite->renderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

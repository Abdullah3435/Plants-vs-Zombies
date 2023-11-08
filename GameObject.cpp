#pragma once
#include "GameObject.hpp"
#include <iostream>
#include <thread>

GameObject::GameObject(int x, int y) {
    transform = new Transform(x, y);
}

void GameObject::SetSprite(SDL_Texture* tex, SDL_Renderer* sourcerenderer)
{
    printf("sprite is set");
    sprite =  new Sprite(tex , SDL_Rect{ 10, 10, 350, 350 },sourcerenderer);
    sprite->rows =16;sprite->cols=5;sprite->Texturewidth = 1760;sprite->Textureheight = 5680;
}

void GameObject::StartAnimation()
{
    printf("creating animation\n");
    animation = new Animation(sprite, 40, 2);

    // Start the animation loop in a separate thread
    std::thread animThread(&Animation::PlayAnimation, animation);
    animThread.detach();  // Detach the thread to run independently
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

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Transform.hpp"
#include "Sprite.hpp"
#include <iostream>

class GameObject {
public:
    Transform* transform;
    Sprite* sprite;
    
public:
    GameObject(int x, int y);

    void SetSprite(SDL_Texture* tex, SDL_Renderer* sourcerenderer);

    Transform* Getposition();

    SDL_Texture* loadTexture(std::string path);
};

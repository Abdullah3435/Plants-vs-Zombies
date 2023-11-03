#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Transform.hpp"
#include <iostream>

class GameObject {
public:
    Transform* transform;
    SDL_Texture* Texture;
    SDL_Rect* Target_Tex; // Part of the Texture to be displayed
    SDL_Renderer* gRenderer;

public:
    GameObject(int x, int y, std::string Tex_path, SDL_Renderer* sourcerenderer);

    Transform* Getposition();

    SDL_Texture* loadTexture(std::string path);
};

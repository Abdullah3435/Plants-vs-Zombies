#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "RenderingMG.hpp"
#include "SpawnMG.hpp"

class Game {
private:
    Texturepaths paths;
    const int SCREEN_WIDTH = 1366;
    const int SCREEN_HEIGHT = 768;
    SDL_Window* gWindow = nullptr;
    SDL_Texture* gTexture = nullptr;
    

    Game();  // Private constructor for singleton pattern

public:
    SDL_Renderer* gRenderer = nullptr;
    Textures assets;
    static Game* getInstance();
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture(std::string path);
    void run();

private:
    static Game* instance;  // Singleton instance
};
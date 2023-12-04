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
#include <vector>
#include <SDL_ttf.h>
#include "PlantMG.hpp"
#include "AudioMG.hpp"

class Game {
private:
    Texturepaths paths;
    const int SCREEN_WIDTH = 1366;
    const int SCREEN_HEIGHT = 768;
    SDL_Window* gWindow = nullptr;
    SDL_Texture* gTexture = nullptr;
    Grid* mygrid;
    PlantManager* PlantMg_script;

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
    void DumpGarbage(GameObject* gameobject);
    void handleKeyboardInput(const SDL_Keysym& keysym);
    void SetSeedIndex(int index);

private:
    static Game* instance;  // Singleton instance
};
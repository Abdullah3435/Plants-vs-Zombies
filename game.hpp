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
#include "ResourceMG.hpp"
#include "ProgressionMG.hpp"

class Game {
private:
    Texturepaths paths;
    const int SCREEN_WIDTH = 1366;
    const int SCREEN_HEIGHT = 768;
    SDL_Window* gWindow = nullptr;
    SDL_Texture* gTexture = nullptr;
    Grid* mygrid;
    PlantManager* PlantMg_script;
    Utilities SunDelay;
    bool Gameover,GameStart,Gamewon;
    
    Game();  // Private constructor for singleton pattern

public:
    ResourceMG _resourcemg; 
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
    bool WelcomeScreen();
    void SetSeedIndex(int index);
    void SpawnSun();
    void saveLevelNumber(int levelNumber);
    int loadLevelNumber();
    void EndGame();
    void StartGame();
    void Updatelevel();
    int getlevel();
    void SetGameOver();
    void quitgame();


private:
    static Game* instance;  // Singleton instance
    int currentlevel = 1; // Set level from here
    bool forcequit;
};
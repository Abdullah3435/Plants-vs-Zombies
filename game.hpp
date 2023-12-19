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

class Plant;//declaration
class Game {
private:
    Texturepaths paths;// Structure to hold paths for textures
    const int SCREEN_WIDTH = 1366;
    const int SCREEN_HEIGHT = 768;
    SDL_Window* gWindow = nullptr;
    SDL_Texture* gTexture = nullptr;
    Grid* mygrid; // Pointer to the game grid
    PlantManager* PlantMg_script; // Pointer to the plant manager script
    Utilities SunDelay;// Utility for sun spawning delay
    bool Gameover,GameStart,Gamewon;// Flags for game state
    
    Game();  // Private constructor for singleton pattern

public:
    ResourceMG _resourcemg; // Resource manager for game assets
    SDL_Renderer* gRenderer = nullptr;
    Textures assets;// Structure to hold loaded textures
    static Game* getInstance(); // Singleton instance getter
    bool init();// Initialize SDL and game components
    bool loadMedia(); // Load game media
    void close();
    SDL_Texture* loadTexture(std::string path);//Load a texture from file
    void run();
    void DumpGarbage(GameObject* gameobject);// Delete and free memory for a game object
    void handleKeyboardInput(const SDL_Keysym& keysym);
    bool WelcomeScreen();// Display the welcome screen
    void SetSeedIndex(int index);
    void SpawnSun();
    void saveLevelNumber(int levelNumber);
    int loadLevelNumber();
    void EndGame();
    void StartGame();// Start the game
    void Updatelevel();
    int getlevel();
    void SetGameOver();
    void quitgame();
    void set_gameWon();// Set the game won state
    void ReduceZombiecount();
    void LeaveGridBlock(Plant*);


private:
    static Game* instance;  // Singleton instance
    int currentlevel = 1; // Set level from here
    bool forcequit, gameovertrig = false;
};
#pragma once

#include "SpawnMG.hpp"
#include "Utilities.hpp"

class LevelManager {
private:
    static LevelManager* instance;// Singleton instance
    int currentWave;// Current wave of zombies
    int zombiesPerWave;// Number of zombies to spawn per wave

    LevelManager();// Private constructor for singleton pattern

public:
    static LevelManager* getInstance();// Function to access the singleton instance
    void startLevel(int level);//Function to start a new level with the specified level number
    void endLevel();// Function to end the current level
    // Functions representing individual level
    void level1();
    void level2();
    void level3();
    void level4();
    void level5();
};
#pragma once

#include "SpawnMG.hpp"
#include "Utilities.hpp"

class LevelManager {
private:
    static LevelManager* instance;
    Spawner* spawner;
    int currentWave;
    int zombiesPerWave;

    LevelManager();

public:
    static LevelManager* getInstance();
    void startLevel(int level);
    // void update();
    void endLevel();
    void level1();
    void level2();
    void level3();
    void level4();
    void level5();
};
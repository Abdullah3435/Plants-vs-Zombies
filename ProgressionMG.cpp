#include "ProgressionMG.hpp"

LevelManager* LevelManager::instance = nullptr;

LevelManager::LevelManager() : currentWave(1), zombiesPerWave(5) {
    // Additional initialization if needed
}

LevelManager* LevelManager::getInstance() {
    if (!instance) {
        instance = new LevelManager();
    }
    return instance;
}

void LevelManager::startLevel(int level) {
    // Initialize your level settings
    // You can set initial delays, wave count, etc.
    switch(level)
    {
        case 1: level1(); break;
        case 2: level2(); break;
        case 3: level3(); break;
        case 4: level4(); break;
        case 5: level5(); break;
        default: level1(); break;
    }



     

    // You can set other parameters as needed
}

void LevelManager::level1()
{
    Spawner::getInstance()->_wavedelay =50000;   // 100 seconds delay between waves         // 60 second delay before starting the level
    Spawner::getInstance()->_spawndelay = 10000;  // 10 second delay between zombie spawns
    Spawner::getInstance()->_generalspawndelay = 10000;
    Spawner::getInstance()->_waveduration = 500; //2 second duration of the wave
    Spawner::getInstance()->no_waves = 1 ; // number of waves to be spawned
};

void LevelManager::level2(){
    Spawner::getInstance()->_wavedelay =50000;   // 100 seconds delay between waves         // 60 second delay before starting the level
    Spawner::getInstance()->_spawndelay = 8000;  // 10 second delay between zombie spawns
    Spawner::getInstance()->_generalspawndelay = 8000;
    Spawner::getInstance()->_waveduration = 700; //2 second duration of the wave
    Spawner::getInstance()->no_waves = 2 ; // number of waves to be spawned

}
void LevelManager::level3(){
    Spawner::getInstance()->_wavedelay =50000;   // 100 seconds delay between waves         // 60 second delay before starting the level
    Spawner::getInstance()->_spawndelay = 6000;  // 10 second delay between zombie spawns
    Spawner::getInstance()->_generalspawndelay = 6000;
    Spawner::getInstance()->_waveduration = 1000; //2 second duration of the wave
    Spawner::getInstance()->no_waves = 2 ; // number of waves to be spawned
}
void LevelManager::level4(){
    Spawner::getInstance()->_wavedelay =50000;   // 100 seconds delay between waves         // 60 second delay before starting the level
    Spawner::getInstance()->_spawndelay = 6000;  // 10 second delay between zombie spawns
    Spawner::getInstance()->_generalspawndelay = 6000;
    Spawner::getInstance()->_waveduration = 2000; //2 second duration of the wave
    Spawner::getInstance()->no_waves = 2 ; // number of waves to be spawned
}
void LevelManager::level5(){
    Spawner::getInstance()->_wavedelay =50000;   // 100 seconds delay between waves         // 60 second delay before starting the level
    Spawner::getInstance()->_spawndelay = 5000;  // 10 second delay between zombie spawns
    Spawner::getInstance()->_generalspawndelay = 5000;
    Spawner::getInstance()->_waveduration = 2000; //2 second duration of the wave
    Spawner::getInstance()->no_waves = 3 ; // number of waves to be spawned
}




#include "SpawnMG.hpp"
Spawner* Spawner::instance = nullptr;

Spawner::Spawner() : zombieInventory(2) {
    _spawndelay = 10000;
    _generalspawndelay = 10000;
    no_waves = 1;
    _passedwaves = 0;
    _waveduration = 100000;
    _wavedelay = 1000; // 1 second wave
    Spawn = true;
    wave = false;
}

Spawner* Spawner::getInstance() {
    if (instance == nullptr) {
        instance = new Spawner();
    }
    return instance;
}

void Spawner::spawnRandomZombie() {
    int ypos[5] = {140,270,400,530,660};
    int spawnposx = 1200;
    int spawnposy = ypos[rand()%5];

    int randomIndex = rand() % 2;
    
    Zombie* newZombie = zombieInventory.createZombie(randomIndex,spawnposx,spawnposy);

    if(newZombie)
    {
        spawnedZombies.push_back(newZombie);
    }
}

void Spawner::update() {
    if (WaveDelay.Delay(_wavedelay)) // check if its the time for wave
    {
        spawnwave();
        wave = true;
    }

    if (wave)// do this only while the wave is being played
    {
       
        if(Waveduration.Delay(_waveduration))//countdown for wave resetting
        {
             _spawndelay = _generalspawndelay ;// back to normal delay
            _passedwaves++;
            if(_passedwaves>=no_waves)
            {
                Spawn = false; //infinite delay
                // GameWonCondition
            }
            wave = false;
        }
    }

    if (SpawnDelay.Delay(_spawndelay)) //spawn zombies RANDOMLY here
    {
        if(Spawn)
        {
        spawnRandomZombie();
        }
    }
    
}

void Spawner::spawnwave()
{
    _spawndelay = 100;
}
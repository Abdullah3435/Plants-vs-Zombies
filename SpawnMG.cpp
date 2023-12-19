
#include "SpawnMG.hpp"
#include "Game.hpp"
Spawner* Spawner::instance = nullptr;

Spawner::Spawner() : zombieInventory(Game::getInstance()->getlevel()) {
    _spawndelay = 10000; // Initial delay between zombie spawns
    _generalspawndelay = 10000;// General delay between waves
    no_waves = 1;
    _passedwaves = 0;
    _waveduration = 100000;// Duration of a wave
    _wavedelay = 1000; // 1 second wave
    Spawn = true;
    wave = false;
}

Spawner::~Spawner()
{
    
}
//to delete the Spawner instance
void Spawner::deleteSpawner()
{
    if (instance)
    {
        delete instance;
    }
    instance = nullptr;
}

//to get the instance of the Spawner class (Singleton pattern)
Spawner* Spawner::getInstance() {
    if (instance == nullptr) {
        instance = new Spawner();
    }
    return instance;
}
//to spawn a random zombie at a random position
void Spawner::spawnRandomZombie() {
    int ypos[5] = {140,270,400,530,660};
    int spawnposx = 1400;
    int spawnposy = ypos[rand()%5];

    int randomIndex = rand() % 5;
     // Create a new Zombie using the ZombieInventory
    Zombie* newZombie = zombieInventory.createZombie(randomIndex,spawnposx,spawnposy);
    // If a new zombie is created, add it to the spawnedZombies vector
    if(newZombie)
    {
        spawnedZombies.push_back(newZombie);
    }
}

void Spawner::update() {
    if (gamewonReady) // game won condition
    {
        if (zombiecount<=0)
        {
            Game::getInstance()->set_gameWon();
        }
    }


    if (WaveDelay.Delay(_wavedelay)) // check if its the time for wave
    {
        std::cout<<"Spawning Wave\n";
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
                std::cout<<"GameWon is true";
                gamewonReady = true;
                ;
                // GameWonCondition
            }
            wave = false;
        }
    }

    if (SpawnDelay.Delay(_spawndelay)) //spawn zombies RANDOMLY here
    {
        if(Spawn)
        {
        std::cout<<"Spawning Zombie\n";
        spawnRandomZombie();
        zombiecount++;
        }
    }
}

void Spawner::spawnwave()
{
    _spawndelay = 100;
}
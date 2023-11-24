#pragma once;
#include "Plant.hpp"

class Seed;

class PlantManager
{
    private :
    Seed* plants[5];
    Seed* selectedplant;
    void Peashooter();
    void Sunflower();
    void WallNut();
    void PotatoMine();
    void CherryBomb();

    public:
    void SelectPlant();
    void createPlant();


    



};
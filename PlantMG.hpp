#pragma once;

class Seed;

class PlantManager
{
    private :
    Seed** plants;
    
    void Peashooter(int x, int y);
    void Sunflower(int x , int y);
    void WallNut(int x, int y);
    void PotatoMine(int x, int y);
    void CherryBomb(int x, int y);

    public:
    Seed* selectedplant;
    int selectedindex;
    void SelectPlant();
    void createPlant(int x, int y);
    void InitializeSeeds(int level);
};
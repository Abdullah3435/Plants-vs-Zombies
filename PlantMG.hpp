#pragma once;

class Seed;

class PlantManager
{
    private :
    Seed* plants[5];
    Seed* selectedplant;
    void Peashooter(int x, int y);
    void Sunflower(int x , int y);
    void WallNut(int x, int y);
    void PotatoMine(int x, int y);
    void CherryBomb(int x, int y);

    public:
    int selectedindex;
    void SelectPlant();
    void createPlant(int i,int x, int y);
};
#pragma once;

class Seed;

class PlantManager
{
    private :
        Seed** plants;// Array to store pointers to Seed objects
        //Plants here
        void Peashooter(int x, int y);
        void Sunflower(int x , int y);
        void WallNut(int x, int y);
        void PotatoMine(int x, int y);
        void CherryBomb(int x, int y);

        //Seeds here
        void PeashooterSeed(int x, int y);
        void SunflowerSeed(int x, int y);
        void WallnutSeed(int x, int y);
        void PotatomineSeed(int x, int y);
        void CherrybombSeed(int x, int y);  

    public:
        Seed* selectedplant;// Pointer to the selected Seed object
        int selectedindex;
        void SelectPlant(); // Function to select the current plant based on the selected index
        void createPlant(int x, int y); // Function to create a plant at the specified location
        void InitializeSeeds(int level);
};
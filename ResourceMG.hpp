#pragma once
#include <iostream>
#include "GameObject.hpp"
#include "RenderingMG.hpp"
#include <vector>

class ResourceMG
{
private:
    int sun;

public:
    ResourceMG();

    void addResource(int amount);

    void subtractResource(int amount);

    int getResources();
};


class Sun:public GameObject, public Clickable
{
    private:
        int Sun_energy = 25;
        bool Fall;
        

    public:
        int Fallduration,elapsedduration;
        Sun(int x , int y);
        void Update();
        void OnClick();
        bool CheckClick(int x, int y);
        
};
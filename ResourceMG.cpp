#include "ResourceMG.hpp"

ResourceMG::ResourceMG() : sun(0) {}

void ResourceMG::addResource(int amount)
{
    sun += amount;
}

void ResourceMG::subtractResource(int amount)
{
    if (sun < amount)
    {
        std::cout << "Not enough resources";
    }
    else
    {
        sun -= amount;
    }
}

int ResourceMG::getResources()
{
    return sun;
}

#include <iostream>
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
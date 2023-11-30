#include "ZombieTemplate.hpp"

// Zombie class implementation
Zombie::Zombie() : movementspeed(1), health(1500), damage(100), State("Idle"){}

void Zombie::UpdateState(std::string _State)
{
    if(_State == "Idle"||_State == "Eat"||_State == "Die")
    {
        if(State == "Die")
        {
            std::cout<<"Can't Change State After Death";
            return;
        }
        State = _State; 
    }

}

// ZombieTemplate class implementation
template <typename... BaseClass>
ZombieTemplate<BaseClass...>::ZombieTemplate(int x, int y) : GameObject(x, y) {}

// Explicit instantiation of ZombieTemplate for specific base classes
template class ZombieTemplate<>;
template class ZombieTemplate<Simple>;
template class ZombieTemplate<Protected>;
template class ZombieTemplate<Utility>;
template class ZombieTemplate<Simple, Protected>;
template class ZombieTemplate<Simple, Utility>;
template class ZombieTemplate<Simple, Protected, Utility>;

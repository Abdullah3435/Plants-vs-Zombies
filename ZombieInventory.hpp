#include "Zombies.hpp"

class ZombieInventory
{
    private:
        Zombie* allzombies[5];

        SimpleZombie* simpleZombie()
        {
            SimpleZombie* myzomb = new SimpleZombie(0,0);
            return myzomb;
        }

        DefensiveZombie* ConeHeadZombie()
        {
            DefensiveZombie* myzomb = new DefensiveZombie(0,0);
            return myzomb;
        }

        SimpleZombie* BucketHeadZombie()
        {
            SimpleZombie* myzomb = new SimpleZombie(0,0);
            return myzomb;
        }

    public:

        ZombieInventory(int level)
        {
            switch(level)
            {
                case 1:
                    allzombies[0] = simpleZombie();
                    break;
                
                case 2:
                    allzombies[0] = simpleZombie();
                    allzombies[1] = ConeHeadZombie();

                    break;
                default:
                    allzombies[0] = simpleZombie();
                    allzombies[1] = ConeHeadZombie();
                    allzombies[2] = BucketHeadZombie();
                    break;
            }
        }


        Zombie* createZombie(int i)
        {
            return allzombies[i]->Clone();
        }
};
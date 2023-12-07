#include "Zombies.hpp"  // Include the header file that declares all the classes
#include "game.hpp"
SimpleZombie::SimpleZombie(int x, int y) :ZombieTemplate<Simple>(x, y),
                                            Walkanim(sprite,20,64,Game::getInstance()->assets.simple_zombie_walk),
                                            Deathanim(sprite,0,34,Game::getInstance()->assets.simple_zombie_die),
                                            Eatanim(sprite,0,39,Game::getInstance()->assets.simple_zombie_eat),Zombie(){}

void SimpleZombie::Update() {

    if (health<0)
    {
        State = "Die";
        // Game::getInstance()->DumpGarbage(this);
        // delete this;
    }

    
    GameObject::Update();
    
    
    
    
    PlayAnim();
    
}

void SimpleZombie::PlayAnim()
{
    if(State == "Idle") //state based conditions check what is the state here
    {
        //std::cout<<sprite<<std::endl;
        sprite = Walkanim.PlayAnimation();
        Move();
    }
    else if(State == "Eat")
    {
         sprite = Eatanim.PlayAnimation();
         if (EatDelay.Delay(1000))
         {
            AudioManager::getInstance()->playSound("chomp");
         }
    }
    else if(State == "Die")
    {
        sprite = Deathanim.PlayAnimation();
        if(DeathDelay.Delay(1200))
        {
            Game::getInstance()->DumpGarbage(this);
            delete this;
        }

    }
}

void SimpleZombie::Move() const {
    transform->translate(-1 * movementspeed);
    // Implementation for moving
}

void SimpleZombie::getDamage(int dmg) {
    health -= dmg;
}

Zombie* SimpleZombie::Clone(int x , int y) {
    Game* game = Game::getInstance();
    SimpleZombie* sz = new SimpleZombie(*this);
    sz->sprite = new Sprite(*this->sprite);
    sz->transform = new Transform (*this->transform);
    sz->setCollider(50,50);
    RenderingMG::getInstance()->myObjs.push_back(sz);
    sz->transform->x = x;
    CollisionMG::getInstance()->AddZombie(sz);

    sz->Walkanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    sz->Eatanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_eat, Game::getInstance()->gRenderer,1130,1210,8,5);
    sz->Deathanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_die, Game::getInstance()->gRenderer,1130,1060,7,5);
    sz->State = "Idle";
    //std::cout<<"THE HEALTH OF THE CLONE IS :"<<health<<std::endl;
    sz->transform->y = y;
    return sz;
}

void SimpleZombie::Attack() const {
    // Implementation for attacking
}

DefensiveZombie::DefensiveZombie(int x, int y) : ZombieTemplate<Simple, Protected>(x, y) ,
                                            Walkanim(sprite,20,64,Game::getInstance()->assets.simple_zombie_walk),
                                            Deathanim(sprite,0,34,Game::getInstance()->assets.simple_zombie_die),
                                            Eatanim(sprite,0,39,Game::getInstance()->assets.simple_zombie_eat),Zombie()
{
    

}
//Operator overloading for adding a protection to zombie
// bind an external protection object to the defensive zombie using Operator overloading
void DefensiveZombie::operator+(GameObject& other)
{
    protection = &other;
}

void DefensiveZombie::Update(){
    if(health <= 500)
    {
        Game::getInstance()->DumpGarbage(protection);
        protection = nullptr;
        delete protection;
    }
    if (health<0)
    {
        State = "Die";
        // Game::getInstance()->DumpGarbage(this);
        // delete this;
    }

    
    GameObject::Update();
    PlayAnim();
    
}


void DefensiveZombie::PlayAnim()
{
    if(State == "Idle") //state based conditions check what is the state here
    {
        //std::cout<<sprite<<std::endl;
        sprite = Walkanim.PlayAnimation();
        Move();
        if(protection)
        {
            protection->transform->x = transform->x;
            protection->transform->y = transform->y-80;
        }
    }
    else if(State == "Eat")
    {
         sprite = Eatanim.PlayAnimation();
         if (EatDelay.Delay(5))
         {
            AudioManager::getInstance()->playSound("chomp");
         }
    }
    else if(State == "Die")
    {
        sprite = Deathanim.PlayAnimation();
        if(DeathDelay.Delay(34))
        {
            Game::getInstance()->DumpGarbage(this);
            delete this;
        }

    }
}

void DefensiveZombie::Move() const {
    transform->translate(-1 * movementspeed);

    // Implementation for moving
}

void DefensiveZombie::Defend(int healthboost) {
    health += healthboost;
    // Implementation for defending
}

void DefensiveZombie::getDamage(int dmg) {
    health -= dmg;
}

Zombie* DefensiveZombie::Clone(int x , int y) {
    Game* game = Game::getInstance();
    DefensiveZombie* sz = new DefensiveZombie(*this);
    sz->sprite = new Sprite(*this->sprite);
    sz->transform = new Transform (*this->transform);
    sz->setCollider(50,50);
    RenderingMG::getInstance()->myObjs.push_back(sz);
    sz->transform->x = x;
    CollisionMG::getInstance()->AddZombie(sz);
    //std::cout<<"THE HEALTH OF THE CLONE IS :"<<health<<std::endl;
    sz->Walkanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    sz->Eatanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_eat, Game::getInstance()->gRenderer,1130,1210,8,5);
    sz->Deathanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_die, Game::getInstance()->gRenderer,1130,1060,7,5);
    sz->State = "Idle";
    sz->protection = new GameObject(*protection);
    sz->protection->sprite = new Sprite(*protection->sprite);
    //std::cout<<"THE HEALTH OF THE CLONE IS :"<<health<<std::endl;
    sz->transform->y = y;
    return sz;
}

void DefensiveZombie::Attack() const {
    // Implementation for attacking
}

UtilityZombie::UtilityZombie(int x, int y) : ZombieTemplate<Simple, Utility>(x, y),
                                        Walkanim(sprite,20,64,Game::getInstance()->assets.simple_zombie_walk),
                                        Deathanim(sprite,0,34,Game::getInstance()->assets.simple_zombie_die),
                                        Eatanim(sprite,0,39,Game::getInstance()->assets.simple_zombie_eat),Zombie(){}

void UtilityZombie::Move() const {
    transform->translate(-1 * movementspeed);
    // Implementation for moving
}

void UtilityZombie::getDamage(int dmg) {
    health -= dmg;
}

void UtilityZombie::SpecialAbility() const {
    // Implementation for special ability
}

void UtilityZombie::Attack() const {
    // Implementation for attacking
}

Zombie* UtilityZombie::Clone(int x , int y) {
    return new UtilityZombie(*this);
}

SuperZombie::SuperZombie(int x, int y) : ZombieTemplate<Simple, Protected, Utility>(x, y) {}

void SuperZombie::Move() const {
    transform->translate(-1 * movementspeed);
    // Implementation for moving
}

void SuperZombie::Update()
{
    GameObject::Update();
    Move();
    if (health<0)
    {
        Game::getInstance()->DumpGarbage(this);
        delete this;
    }
}
void SuperZombie::Defend(int healthboost) {
    // Implementation for defending
    health += healthboost;
}

void SuperZombie::SpecialAbility() const {
    // Implementation for special ability
}

void SuperZombie::getDamage(int dmg) {
    health -= dmg;
}

Zombie* SuperZombie::Clone(int x , int y) {
    Game* game = Game::getInstance();
    SuperZombie* sz = new SuperZombie(*this);
    sz->sprite = new Sprite(*this->sprite);
    sz->transform = new Transform (*this->transform);
    RenderingMG::getInstance()->myObjs.push_back(sz);
    sz->transform->x = x;
    CollisionMG::getInstance()->AddZombie(sz);
    //std::cout<<"THE HEALTH OF THE CLONE IS :"<<health<<std::endl;

    sz->transform->y = y;
    return sz;
}

void SuperZombie::Attack() const {
    // Implementation for attacking
}

SimpleZombie::~SimpleZombie(){};
SuperZombie::~SuperZombie(){};
UtilityZombie::~UtilityZombie(){};
DefensiveZombie::~DefensiveZombie(){};




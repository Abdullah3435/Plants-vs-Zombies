#include "Zombies.hpp"  // Include the header file that declares all the classes
#include "game.hpp"

//constructor
SimpleZombie::SimpleZombie(int x, int y) :ZombieTemplate<Simple>(x, y),
                                            Walkanim(sprite,20,64,Game::getInstance()->assets.simple_zombie_walk),
                                            Deathanim(sprite,0,34,Game::getInstance()->assets.simple_zombie_die),
                                            Eatanim(sprite,0,39,Game::getInstance()->assets.simple_zombie_eat),Zombie(){}

void SimpleZombie::Update() {
    // Check if the zombie reached the left boundary of the screen
    if(transform->x<50)
    {
        Game::getInstance()->SetGameOver();
    }
    // Check if zombie's health is below zero
    if (health<0)
    {
        State = "Die";
    }

    
    GameObject::Update();
    
    
    
    
    PlayAnim();
    
}

//play animation 
void SimpleZombie::PlayAnim()
{
    if(State == "Idle") //state based conditions check what is the state here
    {
        
        sprite = Walkanim.PlayAnimation();
        if(utilities.Delay(100))
        {
            Move();
        }
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
            Game::getInstance()->ReduceZombiecount();
            delete this;
        }

    }
}
// Move the zombie to the left
void SimpleZombie::Move() const {
    
    transform->translate(-1 * movementspeed);
    

}

//reducing zombies health
void SimpleZombie::getDamage(int dmg) {
    health -= dmg;
}

Zombie* SimpleZombie::Clone(int x , int y) {
    // Get the singleton instance of the game
    Game* game = Game::getInstance();
     // Create a new SimpleZombie object as a copy of the current instance
    SimpleZombie* sz = new SimpleZombie(*this);
     // Copy the sprite and transform of the current instance to the new one
    sz->sprite = new Sprite(*this->sprite);
    sz->transform = new Transform (*this->transform);
    // Set collider dimensions for collision detection
    sz->setCollider(50,50);
    // Add the new SimpleZombie to the rendering manager's list of objects
    RenderingMG::getInstance()->myObjs.push_back(sz);
    // Set the x-coordinate of the new SimpleZombie's transform
    sz->transform->x = x;
    // Add the new SimpleZombie to the collision manager's list of zombies
    CollisionMG::getInstance()->AddZombie(sz);

    // Initialize sprite animations for walk, eat, and die
    sz->Walkanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_walk, Game::getInstance()->gRenderer,1130,1987,13,5);
    sz->Eatanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_eat, Game::getInstance()->gRenderer,1130,1210,8,5);
    sz->Deathanim.InitializeSprite(Game::getInstance()->assets.simple_zombie_die, Game::getInstance()->gRenderer,1130,1060,7,5);
     // Set the initial state to idle
    sz->State = "Idle";
     // Set the y-coordinate of the zombie
    sz->transform->y = y;
    return sz;
}

void SimpleZombie::Attack() const {
    // Implementation for attacking
}

// Constructor
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
    // Check if the zombie reached the left boundary of the screen
    if(transform->x<50)
    {
        Game::getInstance()->SetGameOver();
    }
    // Check if zombie's health is below a certain threshold
    if(health <= 500)
    {
        Game::getInstance()->DumpGarbage(protection);
        protection = nullptr;
        delete protection;
    }
    if (health<0)
    {
        State = "Die";
       
    }

    
    GameObject::Update();
    PlayAnim();
    
}

//play animation as per the zombies state
void DefensiveZombie::PlayAnim()
{
    if(State == "Idle") //state based conditions check what is the state here
    {
        sprite = Walkanim.PlayAnimation();
        if(utilities.Delay(100))
        {
            Move();
        }
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
            Game::getInstance()->ReduceZombiecount();
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
// Clone method for DefensiveZombie similar to super zombie
Zombie* DefensiveZombie::Clone(int x , int y) {
    Game* game = Game::getInstance();
    DefensiveZombie* sz = new DefensiveZombie(*this);
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




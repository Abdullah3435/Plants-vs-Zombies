								Welcome to Plants vs. Zombies
Objective:
	Defend your home from the zombie invasion by strategically planting a variety of plants with unique abilities.

Game Basics:
	The game consists of multiple lanes where zombies approach your house.
	You'll see a horizontal grid representing your lawn where you can plant various plants.

Sunflowers:
	Sunflowers generate sunlight, which is your in-game currency.
	Click on the Sunflowers to collect the sunlight they produce.

Sunlight:
	Sunlight is used to plant new plants on your lawn.
	Keep an eye on the sunlight counter at the top of the screen.

Plant Selection:
	Click on the plant icons at the top of the screen to select a plant.
	Different plants have different abilities and costs in sunlight.

Planting:
	Click on an empty square on the lawn to plant the selected plant.
	Some plants have offensive abilities, while others provide defensive support.

Zombie Waves:
	Zombies will approach your house in waves.
	Each wave introduces new types of zombies with different abilities.
	Prepare for stronger waves as you progress.

Plant Types:
1. Peashooter:
Basic offensive plant that shoots peas at zombies.
Good for early defense against basic zombies.

2. Sunflower:
Generates sunlight for planting more plants.
Essential for building a strong defense.

3. Wall-nut:
Defensive plant with high health.
Use Wall-nuts to protect against zombie attacks.

4. Cherry Bomb:
Explosive plant that damages all zombies in a small area.
Use strategically to handle groups of zombies.

Game Strategy:
1. Early Defense
2. Sunflower Management
3. Adapt to Zombie Types
4. Upgrade Plants

Tips:
1. Collect Sunlight
2. Observe Zombie Patterns
3. Experiment with Plant Combinations:

Victory Conditions:
	Successfully defend your house through all waves of zombie attacks. Your victory is secured when you complete the final wave of zombies in each level.


# To compile your .cpp files:

## 1. Build code using the g++ compiler directly

## Note: In order to compile using the g++ compiler you will need to install and setup SDL and the mingw library in your machine's C drive.

- Open this folder in VSCode
- Open VSCode terminal and put this command to compile everything:
	- For Windows:
	`g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o main.exe`

- Run the game by this command:
	- For Windows:
	`.\main.exe`
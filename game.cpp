
#include "game.hpp"
#include <fstream>
#include "Plant.hpp"

Game* Game::instance = nullptr;

Game::Game() {
    // Private constructor for singleton pattern
}

Game* Game::getInstance() {
    if (instance == nullptr) {
        instance = new Game();
    }
    return instance;
}

bool Game::init()
{
	Gameover = false;
	Gamewon = false;
	forcequit = false;
	//Initialization flag
	bool success = true;
	currentlevel =loadLevelNumber();
	mygrid  = new Grid (1100,600,5,9,190,110);
	PlantMg_script = new PlantManager();
	RenderingMG::getInstance()->PMscript = PlantMg_script; // injecting dependency (Sasta Dependency injetion) not at all a good programming practice just testing
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Plants vs Zombies", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );

			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}
	if (TTF_Init() == -1) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "TTF initialization failed: %s", TTF_GetError());
        return false;
    }

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	assets.simple_zombie_walk = loadTexture(paths.SimpleZombietexture);
	assets.simple_zombie_eat = loadTexture(paths.SimpleZombieEat);
	assets.simple_zombie_die = loadTexture(paths.SimpleZombieDie);
	assets.conehead_walk = loadTexture(paths.ConeHead);
	assets.flagzombie_walk=loadTexture(paths.FlagZombie);
	assets.Pea = loadTexture(paths.Pea);
	assets.OpenGame=loadTexture(paths.OpenGame);
	assets.gameover=loadTexture(paths.gameover);
	assets.SeedSlots = loadTexture(paths.SeedSLots);
	assets.Sun = loadTexture(paths.Sun);
	assets.Cone = loadTexture(paths.cone);

	//seeds
	assets.Peashooter_Seed = loadTexture(paths.PeashooterSeed);
	assets.Cherrybomb_Seed = loadTexture(paths.cherrybombseed);
	assets.Sunflower_Seed = loadTexture(paths.sunflowerseed);
	assets.Potatomine_Seed = loadTexture(paths.potatomineseed);
	assets.WallNut_Seed = loadTexture(paths.wallnutseed);

	//plants
	assets.plant_tex = loadTexture(paths.Plantstexture);
	assets.Sunflower = loadTexture(paths.Sunflower);
	assets.WallNut = loadTexture(paths.WallNut);
	assets.CherryBomb = loadTexture(paths.CherryBomb);
	assets.unreadymine = loadTexture(paths.UnreadyMine);
	assets.readymine = loadTexture(paths.readymine);

	assets.gameoverbar = loadTexture(paths.gameoverbar);
	assets.nextlevel = loadTexture(paths.Nextlevel);

    gTexture = loadTexture("BackgroundPVZ.png");
	if(assets.plant_tex==NULL || gTexture==NULL||assets.Peashooter_Seed== NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

void Game::close()
{
	vector<GameObject*> tempobjs = RenderingMG::getInstance()->myObjs;
	for (int i =0;i<tempobjs.size();i++)
	{
		if(tempobjs[i])
		{
			DumpGarbage(tempobjs[i]);
			delete tempobjs[i];
		}
	}
	//Free loaded images
	SDL_DestroyTexture(assets.plant_tex);
	SDL_DestroyTexture(assets.simple_zombie_walk);
	SDL_DestroyTexture(assets.simple_zombie_eat);
	SDL_DestroyTexture(assets.simple_zombie_die);

	assets.plant_tex=NULL;
	assets.simple_zombie_walk=NULL;

	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	saveLevelNumber(currentlevel); //save current progress
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::quitgame()
{
	forcequit = true;
}

void Game::EndGame()
{
	vector<GameObject*> tempobjs = RenderingMG::getInstance()->myObjs;
	for (int i =0;i<tempobjs.size();i++)
	{
		if(tempobjs[i])
		{
			DumpGarbage(tempobjs[i]);
			delete tempobjs[i];
		}
	}

	std::cout<<"Successfully deleted all Game objs";

	// the above will safely dump every game object when engame is called
	RenderingMG::getInstance()->ClearVector();
	CollisionMG::getInstance()->ClearVector();

	Spawner::getInstance()->deleteSpawner();
	std::cout<<"Successfully deleted singletons ";

}

void Game::StartGame()
{
	gameovertrig = false;
	CollisionMG::getInstance();
	RenderingMG::getInstance();

	//AudioManager::getInstance()->playSoundOnLoop("bgMusic");
	PlantMg_script->InitializeSeeds(currentlevel);
	PlantMg_script->selectedplant = nullptr;
	LevelManager::getInstance()->startLevel(currentlevel);
	Gameover = false;
	Gamewon = false;
	Spawner::getInstance()->Spawn = true;
	//Initialization flag
	bool success = true;
	delete mygrid;
	mygrid  = new Grid (1100,600,5,9,190,110);
	std::cout <<"Done everything";

}

void Game::run()
{
	
	bool quit = false;
	SDL_Event e;

	int frames_elapsed = 0;

	
	AudioManager::getInstance()->playSoundOnLoop("bgMusic");
	PlantMg_script->InitializeSeeds(currentlevel);
	PlantMg_script->selectedplant = nullptr;
	quit = WelcomeScreen();
	LevelManager::getInstance()->startLevel(currentlevel);
	
	while( !quit && !forcequit)
	{
		//std::cout<<"D1";
			if(!Gameover)
			{
				SpawnSun();
				
			}
			Spawner::getInstance()->update();
			
			//Handle events on queue
			while( SDL_PollEvent( &e ) != 0 )
			{
				//User requests quit
				if( e.type == SDL_QUIT )
				{
					quit = true;
					Gameover = true;
				}

				if(e.type == SDL_MOUSEBUTTONDOWN){
				//this is a good location to add pigeon in linked list.
					int xMouse, yMouse;
					SDL_GetMouseState(&xMouse,&yMouse);
					//std::cout<<"D2";
					RenderingMG::getInstance()->createObject(xMouse, yMouse,gRenderer,&assets,*mygrid);
					CollisionMG::getInstance()->CheckClicks(xMouse,yMouse);// check for multiple clicks ove here if needed
					//std::cout<<"D3";
				}

				if (e.type == SDL_KEYDOWN)
				{
					handleKeyboardInput(e.key.keysym);
				}
			}

			SDL_RenderClear(gRenderer); //removes everything from renderer
			SDL_Rect* targetbg = new SDL_Rect{100,0,630,489};

			SDL_RenderCopy(gRenderer, gTexture, targetbg, NULL);//Draws background to renderer
			//***********************draw the objects here********************

			//std::cout<<"D4";
			RenderingMG::getInstance()->drawObjects(gRenderer, &assets);
			//std::cout<<"D5";
			CollisionMG::getInstance()->CollisionEventLoop(); //A huge freaking loop
			//std::cout<<"D6";
			TextRenderer::getInstance()->renderText(Game::getInstance()->gRenderer,std::to_string(_resourcemg.getResources()),125,75);//Update Sun Count
			//std::cout<<"D1";
			//****************************************************************
			SDL_RenderPresent(gRenderer); //displays the updated renderer

			SDL_Delay(20);	//causes sdl engine to delay for specified miliseconds //25fps almost
			frames_elapsed++;

	}
}

void Game::DumpGarbage(GameObject* gameObject)
{
	vector<GameObject* >& temp = RenderingMG::getInstance()->myObjs;
	for (int i =0; i<temp.size(); i++)
	{
		if (temp[i] == gameObject)
        {
			//std::cout<<"......NULLIFIEDDDDD....";
            temp[i] = nullptr;
             // No need to continue searching
        }
	}
	CollisionMG::getInstance()->RemoveGameObject(gameObject);
}
	
void Game::LeaveGridBlock(Plant* someplant)
{
	mygrid->unoccupyBlock(someplant->transform->x,someplant->transform->y);
}	
void Game::handleKeyboardInput(const SDL_Keysym& keysym) {
	std::cout<<"keyboard working";
    switch (keysym.sym) {
        case SDLK_1:
            // Handle input for the '1' key
			std::cout<<"1 pressed";//for testing
			PlantMg_script->selectedindex = 0;
            break;
        case SDLK_2:
            // Handle input for the '2' key
			PlantMg_script->selectedindex = 1;
            break;
        case SDLK_3:
            // Handle input for the '3' key
			PlantMg_script->selectedindex = 2;
            break;
        case SDLK_4:
            // Handle input for the '4' key
			PlantMg_script->selectedindex = 3;
            break;
        case SDLK_5:
            // Handle input for the '5' key
            break;
        case SDLK_6:
            // Handle input for the '6' key
            break;
        case SDLK_7:
            // Handle input for the '7' key
            break;
        case SDLK_8:
            // Handle input for the '8' key
            break;
        case SDLK_9:
            // Handle input for the '9' key
            break;
        // Add more cases as needed
        default:
            // Handle any other keys
            break;
    }
}

void Game::SetGameOver()
{
	if(!gameovertrig)
	{
		gameovertrig = true;
	//set game over state using flag
	Gameover = true;
	//disable spawning
	Spawner::getInstance()->Spawn = false;
	// Create game over background and buttons
	GameObject* gameoverbg = new GameObject(600,350);
	Button* restartbutton = new Button (550,430,"Restart");
	Button* End = new Button (650,430,"End");
	// Set sprites for game over elements
	gameoverbg->SetSprite(assets.gameoverbar,gRenderer,717,348); // set all the sprites here
	restartbutton->SetSprite(assets.gameoverbar,gRenderer,717,348);
	End->SetSprite(assets.gameoverbar,gRenderer,717,348);
	// Adjust scale for the game over background
	gameoverbg->transform->x_sc = 8;
	gameoverbg->transform->y_sc = 5;
	// Add game over background for rendering
	AudioManager::getInstance()->playSound("Lost");
	RenderingMG::getInstance()->AddObjectforRendering(gameoverbg);
	//RenderingMG::getInstance()->AddObjectforRendering(restartbutton);
	//RenderingMG::getInstance()->AddObjectforRendering(End);
	// also have to set sprites here
}
}

void Game::set_gameWon()
{
	//flag to set game won state
	Gamewon = true;
	AudioManager::getInstance()->playSound("Won");
	std::cout<<"Set Game Won";
	// Create "Next Level" button
	Button* nextlev = new Button (300,300,"NextLevel");
	// Set sprite for the "Next Level" button
	nextlev->SetSprite(assets.nextlevel,gRenderer,228,51);
	// Add "Next Level" button for rendering
	RenderingMG::getInstance()->AddObjectforRendering(nextlev);
}
void Game::SetSeedIndex(int i)
{
	// Set selected plant index and select the plant
	PlantMg_script->selectedindex = i;
	PlantMg_script->SelectPlant();
}

void Game::Updatelevel()
{
	// Increment current level
	currentlevel ++;
}
int Game::getlevel()
{
	// Return the current level
	return currentlevel;
}

bool Game::WelcomeScreen()
{
	bool Clicked = false;
	SDL_Event e;
	// Handle events until the user clicks
	while( !Clicked)
	{
		
		//Handle events on queue
		while( SDL_PollEvent(&e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				return true;
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				Clicked = true;
			}
		}


		SDL_RenderClear(gRenderer); //removes everything from renderer

		SDL_RenderCopy(gRenderer, assets.OpenGame, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************

		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(20);	//causes sdl engine to delay for specified miliseconds //25fps almost
		//std::cout<<frames_elapsed<<std::endl;
		

	}
	return false;
}

/// to create sun
void Game::SpawnSun()
{
	// Spawn a sun every 5 seconds
	if (SunDelay.Delay(5000))
	{
		new Sun(rand()%1000,0);
	}
}

void Game::saveLevelNumber(int levelNumber) 
{
	// Save the current level number to a file
    std::ofstream file("level_data.txt");
    if (file.is_open()) {
        file << levelNumber;
        file.close();
        std::cout << "Level number saved: " << levelNumber << std::endl;
    } else {
        std::cerr << "Error: Unable to save level number." << std::endl;
    }
}

int Game::loadLevelNumber() {
    int levelNumber = 1; // Default level number if the file is not found or cannot be read
	//Load the level number from level_data.txt file
    std::ifstream file("level_data.txt");
    if (file.is_open()) {
        file >> levelNumber;
        file.close();
        std::cout << "Level number loaded: " << levelNumber << std::endl;
    } else {
        std::cerr << "Warning: Unable to open level data file. Using default level number." << std::endl;
    }
    return levelNumber;
}

void Game::ReduceZombiecount()
{
	// Decrement zombie count in the Spawner
	Spawner::getInstance()->zombiecount--;
}
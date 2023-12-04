
#include "game.hpp"

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
	//Initialization flag
	bool success = true;
	mygrid  = new Grid (1100,600,5,9,190,100);
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
	
	assets.plant_tex = loadTexture(paths.Plantstexture);
	assets.simple_zombie_walk = loadTexture(paths.SimpleZombietexture);
	assets.simple_zombie_eat = loadTexture(paths.SimpleZombieEat);
	assets.simple_zombie_die = loadTexture(paths.SimpleZombieDie);
	assets.conehead_walk = loadTexture(paths.ConeHead);
	assets.flagzombie_walk=loadTexture(paths.FlagZombie);
	assets.Pea = loadTexture(paths.Pea);
	assets.OpenGame=loadTexture(paths.OpenGame);
	assets.gameover=loadTexture(paths.gameover);
	assets.SeedSlots = loadTexture(paths.SeedSLots);
	assets.Peashooter_Seed = loadTexture(paths.PeashooterSeed);
	
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
void Game::run()
{
	
	bool quit = false;
	SDL_Event e;

	int frames_elapsed = 0;

	
	AudioManager::getInstance()->playSoundOnLoop("bgMusic");
	PlantMg_script->InitializeSeeds(1);
	PlantMg_script->selectedplant = nullptr;
	quit = WelcomeScreen();
	
	while( !quit )
	{

		if (frames_elapsed > 1000)// will reset after 1000 frames or 1000/25 = 40seconds
		{
			frames_elapsed = 0;
		}

		if(frames_elapsed %100 == 0)
		{
			Spawner::getInstance()->spawnRandomZombie();
		}
		
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				RenderingMG::getInstance()->createObject(xMouse, yMouse,gRenderer,&assets,*mygrid);
				CollisionMG::getInstance()->CheckClicks(xMouse,yMouse);// check for multiple clicks ove here if needed
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

		RenderingMG::getInstance()->drawObjects(gRenderer, &assets);
		CollisionMG::getInstance()->CollisionEventLoop(); //A huge freaking loop

		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(20);	//causes sdl engine to delay for specified miliseconds //25fps almost
		frames_elapsed++;
		//std::cout<<frames_elapsed<<std::endl;

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
            break;  // No need to continue searching
        }
	}
	CollisionMG::getInstance()->RemoveGameObject(gameObject);
}
	
void Game::handleKeyboardInput(const SDL_Keysym& keysym) {
	std::cout<<"keyboard working" ;
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

void Game::SetSeedIndex(int i)
{
	PlantMg_script->selectedindex = i;
	PlantMg_script->SelectPlant();
}

bool Game::WelcomeScreen()
{
	bool Clicked = false;
	SDL_Event e;

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
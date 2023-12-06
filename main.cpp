#include "game.hpp"

int main(int argc, char *argv[]){
    Game::getInstance();
    srand(time(NULL));
    if( !Game::getInstance()->init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
		//Load media
    if( !Game::getInstance()->loadMedia() ){
        printf( "Failed to load media!\n" );
        return 0;
    }

    Game::getInstance()->run();
    Game::getInstance()->close();
    return 0;
}  
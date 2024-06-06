#include "C110152325_Game.h"


int main(){

	srand(time(NULL));

	C110152325_Game game;
	game.initGame();

	while (game.getplaying()) {
		game.mainMenu();
	}




	return 0;
}
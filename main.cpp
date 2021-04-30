#include "Game.h"
#include <ncurses.h>

int main(){
	initscr();
	Game* g = Game::GetInstance();
	g->New_Game();
	endwin();
	return 0;
}

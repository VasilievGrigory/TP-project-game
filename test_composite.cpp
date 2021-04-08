#include "lib.h"
#include <iostream>
int main() {
	initscr();
   	Unite* u = new Human;
    	Unite* mg_h = new Mage(u);
    	Unite* u1 = new Human;
    	Unite* wr_h = new Warrior(u1);
    	Unite* u2 = new Elf;
    	Unite* a = new Archer(u2);
    	Composite_Humans* crowd = new Composite_Humans;
	printw("How many humans in crowd: ");
    	printw("%d\n", crowd->how_many_humans);
    	crowd->add(mg_h);
    	crowd->add(wr_h);
	printw("Enemy HP: ");
    	printw("%d\n", a->current_hp());
    	crowd->HUMANS_POWER(a);
	printw("Here was a hit\nEnemy HP: ");
    	printw("%d\n", a->current_hp());
    	crowd->remove(mg_h);
	printw("How many humans in crowd: ");
    	printw("%d\n", crowd->how_many_humans);
	getch();
    	endwin();
    	return 0;
}

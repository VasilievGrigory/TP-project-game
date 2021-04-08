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
    Warrior* copy = dynamic_cast<Warrior*> (wr_h);
    printw("Enemy_HP: ");
    printw("%d\n", a->current_hp());
    printw("Unite act_points: ");
    printw("%d\n", copy->current_act_points());
    copy->strong_hit(a);
    printw("Enemy_HP: ");
    printw("%d\n", a->current_hp());
    printw("Enemy act_points: ");
    printw("%d\n", a->current_act_points());
    printw("Unite act_points: ");
    printw("%d\n", copy->current_act_points());
    copy->hit_with_stun(a);
    printw( "(few act_points)\nEnemy act_points: ");
    printw("%d\n", a->current_act_points());
    printw("Enemy_HP: ");
    printw("%d\n", a->current_hp());
    getch();
    endwin();
}

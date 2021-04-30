//#include "Unite.h"
#include <vector>
#include <string>
#include <ncurses.h>
class Mage :public Unite {
public:
	int health = 60;
	int action_points = 3;
	int initiative = 8;
	int position = 0;
	Unite* stats_ = new Unite;
	Mage(){
		stats_->health = 60;
		stats_->action_points = 3;
		stats_->initiative = 8;
		stats_->position = 0;
	}
	Mage (int pos){
		health = 60;
		action_points = 3;
		initiative = 8;
		position = pos;
	}
	int max_health() {
		return 60;
	}
	void common_hit(Unite& u) {
		if (this->action_points < 1 || u.is_dead()) {
			printw( "It's impossible!\n");
			return;
		}
		u.decrease_hp(15);
		this->action_points--;
	}
	void fireball(Unite& u) {
		if (this->action_points < 2 || u.is_dead()) {
			printw( "It's impossible!\n");
			return;
		}
		u.decrease_hp(35);
		this->action_points -= 2;
	}
	void heal(Unite& u) {
		if (this->action_points < 2) {
			printw( "It's impossible!\n");
			return;
		}
		u.decrease_hp(-10);
		this->action_points -= 2;
	}
	~Mage() = default;
};

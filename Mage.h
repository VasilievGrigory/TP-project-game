//#include "Unite.h"
#include <vector>
#include <string>
#include <ncurses.h>
class Mage :public Unite {
private:
	static const int health = 60;
	static const int action_points = 3;
	static const int initiative = 8;
	int position = 0;
public:
	Unite* stats_ = new Unite;
	Mage(){
		stats_->health = 60;
		stats_->action_points = 3;
		stats_->initiative = 8;
		stats_->position = 0;
	}
	Mage (int pos){
		stats_->health = 60;
		stats_->action_points = 3;
		stats_->initiative = 8;
		stats_->position = pos;
		position = pos;
	}
	int max_health() {
		return 60;
	}
	void common_hit(Unite& u) {
		if (this->stats_->action_points < 1 || u.is_dead()) {
			printw( "It's impossible!\n");
			return;
		}
		u.decrease_hp(15);
		this->stats_->action_points--;
	}
	void fireball(Unite& u) {
		if (this->stats_->action_points < 2 || u.is_dead()) {
			printw( "It's impossible!\n");
			return;
		}
		u.decrease_hp(35);
		this->stats_->action_points -= 2;
	}
	void heal(Unite& u) {
		if (this->stats_->action_points < 2) {
			printw( "It's impossible!\n");
			return;
		}
		u.decrease_hp(-10);
		this->stats_->action_points -= 2;
	}
	~Mage() = default;
};

//#include "Unite.h"
#include <ncurses.h>
#include <vector>
#include <string>
class Warrior :public Unite {
public:
	int health = 100;
	int action_points = 3;
	int initiative = 4;
	int position = 0;
	Unite* stats_ = new Unite;
	Warrior(){
		stats_->health = 60;
		stats_->action_points = 3;
		stats_->initiative = 8;
		stats_->position = 0;
	}
        Warrior (int pos){
                health = 100;
                action_points = 3;
                initiative = 4;
                position = pos;
        }
	int max_health() {
		return 100;
	}
	void common_hit(Unite& u) {
		if (this->action_points < 1 || u.is_dead()) {
			printw("I can't do this!\n");
			return;
		}
		u.decrease_hp(10);
		this->action_points--;
	}
	void hit_with_stun(Unite& u) {
		if (this->action_points < 2 || u.is_dead()) {
			printw("I can't do this!\n");
			return;
		}
		u.decrease_hp(30);
		u.decrease_act_points(u.current_act_points());
		this->action_points -= 3;
	}
	void strong_hit(Unite& u) {
		if (this->action_points < 2 || u.is_dead()) {
			printw("I can't do this!\n");
			return;
		}
		u.decrease_hp(30);
		this->action_points -= 2;
	}
	~Warrior() = default;
};

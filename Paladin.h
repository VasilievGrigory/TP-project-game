#include <vector>
#include <string>
#include <ncurses.h>
//#include "Unite.h"
class Paladin :public Unite {
public:
	int health = 85;
	int action_points = 3;
	int initiative = 7;
	int position = 0;
	Unite* stats_ = new Unite;
	Paladin(){
		stats_->health = 60;
		stats_->action_points = 3;
		stats_->initiative = 8;
		stats_->position = 0;
	}
        Paladin (int pos){
                health = 85;
                action_points = 3;
                initiative = 7;
                position = pos;
        }
	int max_health() {
		return 85;
	}
	void common_hit(Unite& u) {
		if (this->action_points < 1 || u.is_dead()) {
			printw("It's impossible!\n");
			return;
		}
		u.decrease_hp(15);
		this->action_points--;
	}
	void hit_with_blind(Unite& u) {
		if (this->action_points < 2 || u.is_dead()) {
			printw("It's impossible!\n");
			return;
		}
		u.decrease_hp(20);
		u.decrease_act_points(3);
		this->action_points -= 2;
	}
	void blessing(Unite& u) {
		if (this->action_points < 3) {
			printw("It's impossible!\n");
			return;
		}
		u.decrease_hp(-10);
		u.decrease_act_points(-2);
		this->action_points -= 3;
	}
	~Paladin() = default;
};

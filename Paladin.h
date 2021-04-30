#include <vector>
#include <string>
#include <ncurses.h>
//#include "Unite.h"
class Paladin :public Unite {
private:
	static const int health = 85;
	static const int action_points = 3;
	static const int initiative = 7;
	int position = 0;
public:
	Unite* stats_ = new Unite;
	Paladin(){
		stats_->health = 85;
		stats_->action_points = 3;
		stats_->initiative = 7;
		stats_->position = 0;
	}
        Paladin (int pos){
                stats_->health = 85;
		stats_->action_points = 3;
		stats_->initiative = 7;
		stats_->position = pos;
                position = pos;
        }
	int max_health() {
		return 85;
	}
	void common_hit(Unite& u) {
		if (this->stats_->action_points < 1 || u.is_dead()) {
			printw("It's impossible!\n");
			return;
		}
		u.decrease_hp(15);
		this->stats_->action_points--;
	}
	void hit_with_blind(Unite& u) {
		if (this->stats_->action_points < 2 || u.is_dead()) {
			printw("It's impossible!\n");
			return;
		}
		u.decrease_hp(20);
		u.decrease_act_points(3);
		this->stats_->action_points -= 2;
	}
	void blessing(Unite& u) {
		if (this->stats_->action_points < 3) {
			printw("It's impossible!\n");
			return;
		}
		u.decrease_hp(-10);
		u.decrease_act_points(-2);
		this->stats_->action_points -= 3;
	}
	~Paladin() = default;
};

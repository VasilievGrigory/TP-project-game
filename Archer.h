#include <ncurses.h>
#include <vector>
#include <string>
//#include "Unite.h"
class Archer :public Unite {
private:
	static const int health = 70;
	static const int action_points = 4;
	static const int initiative = 6;
	int position = 0;
public:
	Unite* stats_ = new Unite;
	Archer(){
		stats_->health = 70;
		stats_->action_points = 4;
		stats_->initiative = 6;
		stats_->position = 0;
	}
        Archer (int pos){
                position = pos;
                stats_->health = 70;
		stats_->action_points = 4;
		stats_->initiative = 6;
		stats_->position = pos;
        }
	int max_health() {
		return 70;
	}
	void common_hit(Unite & u) {
		if (this->stats_->action_points < 1 || u.is_dead()) {
			printw("It can't be done!\n");
			return;
		}
		u.decrease_hp(10);
		this->stats_->action_points--;
	}
	void deadly_arrow(Unite & u) {
		if (this->stats_->action_points < 3 || u.is_dead()) {
			printw("It can't be done!\n");
			return;
		}
		u.decrease_hp(10);
		if (u.current_hp() <= 20) {
			u.decrease_hp(u.current_hp());
		}
		this->stats_->action_points -= 3;
	}
	void drag_arrow(Unite & u) {
		if (this->stats_->action_points < 2 || u.is_dead()) {
			printw("It can't be done!\n");
			return;
		}
		u.decrease_hp(30);
		this->stats_->action_points -= 2;
	}
	~Archer() = default;
};

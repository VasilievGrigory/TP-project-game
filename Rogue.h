#include <vector>
#include <string>
#include <ncurses.h>
//#include "Unite.h"
class Rogue :public Unite {
public:
	int health = 60;
	int action_points = 4;
	int initiative = 7;
	int position = 0;
	Unite* stats_ = new Unite;
	Rogue(){
		stats_->health = 60;
		stats_->action_points = 3;
		stats_->initiative = 8;
		stats_->position = 0;
	}
        Rogue (int pos){
                health = 60;
                action_points = 4;
                initiative = 7;
                position = pos;
        }
	int max_health() {
		return 60;
	}
	void common_hit(Unite& u) {
		if (this->action_points < 1 || u.is_dead()) {
			printw("It's impossible!\n");
			return;
		}
		u.decrease_hp(15);
		this->action_points--;
	}
	void blade_of_shadow(Unite& u) {
		if (this->action_points < 2 || u.is_dead()) {
			printw("It's impossible!\n");
			return;
		}
		u.decrease_hp(10);
		if (u.current_hp()<=0){
			this->action_points++;
			this->health+=10;
		}
		this->action_points -= 2;
	}
	void irrepressibility(Unite& u) {
		if (u.is_dead()){
			printw("This is silly...\n");
			return;
		}
		if(this->action_points<3){
			printw("It's impossible!\n");
			return;
		}
		u.decrease_act_points(-3);
		this->action_points-=2;
	}
	~Rogue() = default;
};

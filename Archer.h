#include <ncurses.h>
#include <vector>
#include <string>
//#include "Unite.h"
class Archer :public Unite {
public:
	int health = 70;
	int action_points = 4;
	int initiative = 6;
	int position = 0;
        Archer (int pos){
                health = 70;
                action_points = 4;
                initiative = 6;
                position = pos;
        }
        int current_pos(){
                return this->position;
        }
	Archer() = default;
	int max_health() {
		return 70;
	}
	int  current_hp(){
                return this->health;
        }
	int  current_act_points(){
                return this->action_points;
        }
	void decrease_hp(int damage){
                this->health -= damage;
        }
        void decrease_act_points(int damage_points){
                this->action_points -= damage_points;
        }
	void common_hit(Unite & u) {
		if (this->action_points < 1 || u.is_dead()) {
			printw("It can't be done!\n");
			return;
		}
		u.decrease_hp(10);
		this->action_points--;
	}
	void deadly_arrow(Unite & u) {
		if (this->action_points < 3 || u.is_dead()) {
			printw("It can't be done!\n");
			return;
		}
		u.decrease_hp(10);
		if (u.current_hp() <= 20) {
			u.decrease_hp(u.current_hp());
		}
		this->action_points -= 3;
	}
	void drag_arrow(Unite & u) {
		if (this->action_points < 2 || u.is_dead()) {
			printw("It can't be done!\n");
			return;
		}
		u.decrease_hp(30);
		this->action_points -= 2;
	}
	bool is_dead() {
		if (this->health <= 0) {
			return true;
		}
		return false;
	}
	~Archer() = default;
};

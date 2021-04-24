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
        Warrior (int pos){
                health = 100;
                action_points = 3;
                initiative = 4;
                position = pos;
        }
        int current_pos(){
                return this->position;
        }
	Warrior() = default;
	int max_health() {
		return 100;
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
	bool is_dead() {
		if (this->health <= 0) {
			return true;
		}
		return false;
	}
	~Warrior() = default;
};

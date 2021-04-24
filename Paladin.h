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
        Paladin (int pos){
                health = 85;
                action_points = 3;
                initiative = 7;
                position = pos;
        }
        int current_pos(){
                return this->position;
        }
	Paladin() = default;
	int max_health() {
		return 85;
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
	bool is_dead() {
		if (this->health <= 0) {
			return true;
		}
		return false;
	}
	~Paladin() = default;
};

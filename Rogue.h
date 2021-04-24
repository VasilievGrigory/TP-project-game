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
        Rogue (int pos){
                health = 60;
                action_points = 4;
                initiative = 7;
                position = pos;
        }
        int current_pos(){
                return this->position;
        }

	Rogue() = default;
	int max_health() {
		return 60;
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
	bool is_dead() {
		if (this->health <= 0) {
			return true;
		}
		return false;
	}
	~Rogue() = default;
};

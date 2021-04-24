//#include "Unite.h"
#include <vector>
#include <string>
#include <ncurses.h>
class Mage :public Unite {
public:
	int health = 60;
	int action_points = 3;
	int initiative = 8;
	int position = 0;
	Mage (int pos){
		health = 60;
		action_points = 3;
		initiative = 8;
		position = pos;
	}
	int current_pos(){
		return this->position;
	}
	Mage() = default;
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
			printw( "It's impossible!\n");
			return;
		}
		u.decrease_hp(15);
		this->action_points--;
	}
	void fireball(Unite& u) {
		if (this->action_points < 2 || u.is_dead()) {
			printw( "It's impossible!\n");
			return;
		}
		u.decrease_hp(35);
		this->action_points -= 2;
	}
	void heal(Unite& u) {
		if (this->action_points < 2 || u.max_health()==u.current_hp()) {
			printw( "It's impossible!\n");
			return;
		}
		u.decrease_hp(-10);
		this->action_points -= 2;
	}
	bool is_dead() {
		if (this->health <= 0) {
			return true;
		}
		return false;
	}
	~Mage() = default;
};

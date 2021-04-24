#include <vector>
#include <string>
#include <ncurses.h>
#//include "Unite.h"
class Easy_enemy :public Unite {
public:
	int health = 50;
	int action_points = 3;
	int initiative = 3;
	int position = 0;
	int current_pos(){
		return this->position;
	}
	Easy_enemy() = default;
	int max_health() {
		return 50;
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
			printw("NO!\n");
			return;
		}
		u.decrease_hp(10);
		this->action_points--;
	}
	bool is_dead() {
		if (this->health <= 0) {
			return true;
		}
		return false;
	}
	~Easy_enemy() = default;
};

class Medium_enemy :public Unite {
public:
	int health = 70;
	int action_points = 3;
	int initiative = 5;
	int position = 0;
        int current_pos(){
                return this->position;
        }
	Medium_enemy() = default;
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
	void common_hit(Unite& u) {
		if (this->action_points < 1 || u.is_dead()) {
			printw("NO!\n");
			return;
		}
		u.decrease_hp(15);
		this->action_points--;
	}
	bool is_dead() {
		if (this->health <= 0) {
			return true;
		}
		return false;
	}
	~Medium_enemy() = default;
};

class Hard_enemy :public Unite {
public:
	int health = 80;
	int action_points = 4;
	int initiative = 7;
	int position = 0;
        int current_pos(){
                return this->position;
        }
	Hard_enemy() = default;
	int max_health() {
		return 80;
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
			printw("NO!\n");
			return;
		}
		u.decrease_hp(20);
		this->action_points--;
	}
	bool is_dead() {
		if (this->health <= 0) {
			return true;
		}
		return false;
	}
	~Hard_enemy() = default;
};

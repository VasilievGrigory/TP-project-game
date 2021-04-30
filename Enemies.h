#include <vector>
#include <string>
#include <ncurses.h>
#//include "Unite.h"
class Easy_enemy :public Unite {
private:
	static const int health = 50;
	static const int action_points = 3;
	static const int initiative = 3;
	int position = 0;
public:
	Unite* stats_ = new Unite;
	Easy_enemy(){
		stats_->health = 50;
		stats_->action_points = 3;
		stats_->initiative = 3;
		stats_->position = 0;
	}
	int max_health() {
		return 50;
	}
	void common_hit(Unite& u) {
		if (this->stats_->action_points < 1 || u.is_dead()) {
			printw("NO!\n");
			return;
		}
		u.decrease_hp(10);
		this->stats_->action_points--;
	}
	~Easy_enemy() = default;
};

class Medium_enemy :public Unite {
private:
	static const int health = 70;
	static const int action_points = 3;
	static const int initiative = 5;
	int position = 0;
public:
	Unite* stats_ = new Unite;
	Medium_enemy(){
		stats_->health = 70;
		stats_->action_points = 3;
		stats_->initiative = 5;
		stats_->position = 0;
	}
	int max_health() {
		return 70;
	}
	void common_hit(Unite& u) {
		if (this->stats_->action_points < 1 || u.is_dead()) {
			printw("NO!\n");
			return;
		}
		u.decrease_hp(15);
		this->stats_->action_points--;
	}
	~Medium_enemy() = default;
};

class Hard_enemy :public Unite {
private:
	static const int health = 80;
	static const int action_points = 4;
	static const int initiative = 7;
	int position = 0;
public:
	Unite* stats_ = new Unite;
	Hard_enemy(){
		stats_->health = 80;
		stats_->action_points = 4;
		stats_->initiative = 7;
		stats_->position = 0;
	}
	int max_health() {
		return 80;
	}
	void common_hit(Unite& u) {
		if (this->stats_->action_points < 1 || u.is_dead()) {
			printw("NO!\n");
			return;
		}
		u.decrease_hp(20);
		this->stats_->action_points--;
	}
	~Hard_enemy() = default;
};

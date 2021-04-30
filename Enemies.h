class Easy_enemy :public Unite {
public:
	int health = 50;
	int action_points = 3;
	int initiative = 3;
	int position = 0;
	Unite* stats_ = new Unite;
	Easy_enemy(){
		stats_->health = health;
		stats_->action_points = action_points;
		stats_->initiative = initiative;
		stats_->position = position;
	};
	int max_health() {
		return 50;
	}
	void common_hit(Unite& u) {
		if (this->action_points < 1 || u.is_dead()) {
			printw("NO!\n");
			return;
		}
		u.decrease_hp(10);
		this->action_points--;
	}
	~Easy_enemy() = default;
};

class Medium_enemy :public Unite {
public:
	int health = 70;
	int action_points = 3;
	int initiative = 5;
	int position = 0;
        Unite* stats_ = new Unite;
	Medium_enemy(){
		stats_->health = health;
		stats_->action_points = action_points;
		stats_->initiative = initiative;
		stats_->position = position;
	};
	int max_health() {
		return 70;
	}
	void common_hit(Unite& u) {
		if (this->action_points < 1 || u.is_dead()) {
			printw("NO!\n");
			return;
		}
		u.decrease_hp(15);
		this->action_points--;
	}
	~Medium_enemy() = default;
};

class Hard_enemy :public Unite {
public:
	int health = 80;
	int action_points = 4;
	int initiative = 7;
	int position = 0;
        Unite* stats_ = new Unite;
	Hard_enemy(){
		stats_->health = health;
		stats_->action_points = action_points;
		stats_->initiative = initiative;
		stats_->position = position;
	};
	int max_health() {
		return 80;
	}
	void common_hit(Unite& u) {
		if (this->action_points < 1 || u.is_dead()) {
			printw("NO!\n");
			return;
		}
		u.decrease_hp(20);
		this->action_points--;
	}
	~Hard_enemy() = default;
};
